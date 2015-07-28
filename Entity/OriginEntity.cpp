#include "OriginEntity.h"

OriginEntity::OriginEntity(){
    this->setEntityName("OriginEntity");
}

OriginEntity::~OriginEntity(){
}

void OriginEntity::setEntityName(string entityName){
    this->EntityName = entityName;
}

void OriginEntity::initFromVector(){
}


void OriginEntity::readNextStream(istream& istr){
    string line;
    getline(istr, line);

    stringstream lineStream(line);

    this->mVector = split(istr, ",");
    initFromVector();
}

void OriginEntity::readFromString(string str){
    this->mVector = split(str, ",");
    initFromVector();
}

void OriginEntity::readFromCSVIterator(CSVIterator csvItr){
    this->mVector.clear();
    for(size_t i = 0; i < (*csvItr).size(); i++){
        mVector.push_back((*csvItr)[i]);
    }
    initFromVector();
}
