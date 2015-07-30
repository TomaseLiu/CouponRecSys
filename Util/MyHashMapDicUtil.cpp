#include "MyHashMapDicUtil.h"


long HashDict::StaticLongID = 0;

HashDict::HashDict(){
    this->HashStr2ID.clear();
    this->ID2HashStr.clear();
}

HashDict::~HashDict(){
    this->HashStr2ID.clear();
    this->ID2HashStr.clear();
}

long HashDict::InsertAHashStr(string hashStr){
    if(this->HashStr2ID.count(hashStr) == 0){
        this->HashStr2ID[hashStr] = StaticLongID;
        this->ID2HashStr[StaticLongID] = hashStr;
        ++StaticLongID;
    }
    return StaticLongID;
}

void HashDict::InsertAPair(string hashStr, long longID){
    if(this->HashStr2ID[hashStr]!=0 && this->HashStr2ID[hashStr]!=longID){
        cout << "map conflict" << " key: " << hashStr << " OriValue: " << this->HashStr2ID[hashStr] << " NewValue: " << longID << endl;
        return;
    }
    this->HashStr2ID[hashStr] = longID;
    this->ID2HashStr[longID] = hashStr;
}

long HashDict::GetLongID(string hashStr){
    if(this->HashStr2ID.count(hashStr) != 0)
        return this->HashStr2ID[hashStr];
    return -1;
}

string HashDict::GetHashStr(long longID){
    string ret;
    if(this->ID2HashStr.count(longID) != 0)
        ret = this->ID2HashStr[longID];
    return ret;
}

long HashDict::GetStaticLongID(){
    return StaticLongID;
}

map<string, long>::iterator HashDict::getBeginOfHashDict(){
    map<string, long>::iterator itr = this->HashStr2ID.begin();
    return itr;
}

map<string, long>::iterator HashDict::getEndOfHashDict(){
    map<string, long>::iterator itr = this->HashStr2ID.end();
    return itr;
}

size_t HashDict::getSize(){
    return this->HashStr2ID.size();
}

HashDict initHashDictFromFile(string filePath, int coulumIndex){

    HashDict hashDict;

    ifstream ifile(filePath.c_str());

    CSVIterator loop(ifile);
    int fileCoulumnNum = int((*loop).size());
    if(coulumIndex >= fileCoulumnNum){
        cout << "bad coulumn index direct to hashStr" << endl;
        return hashDict;
    }
    if(coulumIndex < 0){
        coulumIndex = fileCoulumnNum+coulumIndex;
    }
    ++loop;
    for(; loop != CSVIterator(); ++loop){
        string hashStr = (*loop)[coulumIndex];
        hashDict.InsertAHashStr(hashStr);
    }
    ifile.close();
    return hashDict;
}


void writeHashDictIntoFile(string filePath, HashDict &hashDict){
    ofstream ofile(filePath.c_str());
    for(map<string, long>::iterator itr = hashDict.getBeginOfHashDict(); itr != hashDict.getEndOfHashDict(); ++itr){
        string hashStr = itr->first;
        long longID = itr->second;
        ofile << hashStr << "\t" << longID << endl;
    }
    ofile.close();
}

HashDict getHashDictFromFile(string filePath){
    HashDict hashDict;
    ifstream ifile(filePath.c_str());
    string hashStr;
    long longID;
    while(ifile >> hashStr >> longID){
        hashDict.InsertAPair(hashStr, longID);
    }
    return hashDict;
}
