#include "OriginUser.h"

OriginUser::OriginUser(){
    setEntityName("OriginUser");
}

OriginUser::~OriginUser(){
}

void OriginUser::initFromVector(){
    if(this->mVector.size() == 6){
        this->RegDate = convert<string>(this->mVector[0]);
        this->SexFemale = convert<string>(this->mVector[1]);
        this->Age = convert<int>(this->mVector[2]);
        this->WdwDate = convert<string>(this->mVector[3]);
        this->PrefName = convert<string>(this->mVector[4]);
        this->UserID = convert<string>(this->mVector[5]);

        cout << UserID << " " << PrefName << " " << RegDate << " " << Age << endl;
    }
}

string OriginUser::getUserID(){
    return this->UserID;
}

void OriginUser::setUserID(string userId){
    this->UserID = userId;
}

string OriginUser::getPrefName(){
    return this->PrefName;
}

void OriginUser::setPrefName(string prefName){
    this->PrefName = prefName;
}

string OriginUser::getSexFemale(){
    return this->SexFemale;
}

void OriginUser::setSexFemale(string sexFemale){
    this->SexFemale = sexFemale;
}

int OriginUser::getAge(){
    return this->Age;
}

void OriginUser::setAge(int age){
    this->Age = age;
}

string OriginUser::getRegDate(){
    return this->RegDate;
}

void OriginUser::setRegDate(string regDate){
    this->RegDate = regDate;
}

string OriginUser::getWdwDate(){
    return this->WdwDate;
}

void OriginUser::setWdwDate(string wdwDate){
    this->WdwDate = wdwDate;
}
