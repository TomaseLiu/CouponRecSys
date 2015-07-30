#ifndef MYHASHMAPDICUTIL_H_INCLUDED
#define MYHASHMAPDICUTIL_H_INCLUDED
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

#include "CSVFileUtil.h"

using namespace std;

class HashDict{

    map<string, long> HashStr2ID;
    map<long, string> ID2HashStr;
    static long StaticLongID;

    public:
        HashDict();

        virtual ~HashDict();

        long InsertAHashStr(string hashStr);

        void InsertAPair(string hashStr, long longID);

        long GetLongID(string hashStr);

        string GetHashStr(long longID);

        long GetStaticLongID();

        map<string, long>::iterator getBeginOfHashDict();

        map<string, long>::iterator getEndOfHashDict();

        size_t getSize();

};

HashDict initHashDictFromFile(string filePath, int coulumIndex);

HashDict getHashDictFromFile(string filePath);

void writeHashDictIntoFile(string filePath);

#endif // MYHASHMAPDICUTIL_H_INCLUDED
