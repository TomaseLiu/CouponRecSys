#ifndef MYFILEREADER_H_INCLUDED
#define MYFILEREADER_H_INCLUDED

#include <fstream>
#include "OriginEntity.h"
#include <vector>
#include <string>
#include "CSVFileUtil.h"

using namespace std;

template<class T>
vector<T*> readOriginEntityFromFile(string filePath){
    vector<T*> ret;
    ifstream ifile(filePath.c_str());
    CSVIterator loop(ifile);
    ++loop;
    for(; loop != CSVIterator(); ++loop){
        T *t = new T();
        t->readFromCSVIterator(loop);
        ret.push_back(t);
    }
    ifile.close();
    return ret;
}

#endif // MYFILEREADER_H_INCLUDED
