#ifndef DATAFORMATUTIL_H_INCLUDED
#define DATAFORMATUTIL_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <class T>
string inline toString(T a){
    stringstream SS;
    SS << a;
    string str = SS.str();
    return str;
}

template <class T>
void inline Append2String(string& ret, T a){
    stringstream SS;
    SS << ret << (ret.size() == 0 ? "" : ",");
    SS << a;
    ret = SS.str();
}

template <class T>
stringstream& Append2String(string&ret, T a, stringstream &ss){
    ss << ret << (ret.size() == 0 ? "" : ",");
    ss << a;
    ret = ss.str();
    return ss;
}

template<class out_type, class in_value>
out_type convert(const in_value & t){
    stringstream stream;
    stream << t;
    out_type result;
    stream >> result;
    return result;
}


vector<string> inline split(string oriStr, string spltSymbol){
    size_t pos;
    vector<string> spltRet;
    oriStr += spltSymbol;
    for(size_t i = 0; i < oriStr.size(); i++){
        pos = oriStr.find(spltSymbol, i);
        if(pos < oriStr.size()){
            string s = oriStr.substr(i, pos-i);
            spltRet.push_back(s);
            i = pos+spltSymbol.size()-1;
        }
    }
    return spltRet;
}

vector<string> inline split(istream &istr, string spltSym){
    string tmpStr;
    istr >> tmpStr;
    return split(tmpStr, spltSym);
}

string inline JoinVectorItems(vector<string> oriVec, string spltSym){
    string ret;
    if(oriVec.size() != 0)
        ret = oriVec[0];
    for(size_t i = 1; i < oriVec.size(); i++){
        ret += spltSym + oriVec[i];
    }
    return ret;
}

#endif // DATAFORMATUTIL_H_INCLUDED
