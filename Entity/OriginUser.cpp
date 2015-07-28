#include "OriginUser.h"

OriginUser::OriginUser(){
    setEntityName("OriginUser");
}

OriginUser::~OriginUser(){
}

void OriginUser::initFromVector(vector<string> mVector){
    if(mVector.size() == 6){
        this->UserID = convert<string>(mVector[0]);
        this->PrefName = convert<string>(mVector[1]);
        this->SexFemale = convert<string>(mVector[2]);
        this->Age = convert<int>(mVector[3]);
        this->RegDate = convert<string>(mVector[4]);
        this->WdwDate = convert<string>(mVector[5]);
    }
}

void OriginUser::readNextStream(istream& istr){
    string line;
    getline(istr, line);

    stringstream lineStream(line);

    vector<string> mVector = split(istr, ",");
    initFromVector(mVector);
}

void OriginUser::readFromString(string str){
    vector<string> mVector = split(str, ",");
    initFromVector(mVector);
}
