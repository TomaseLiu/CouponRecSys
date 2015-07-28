#include "OriginEntity.h"

OriginEntity::OriginEntity(){
    this->setEntityName("OriginEntity");
}

OriginEntity::~OriginEntity(){
}

void OriginEntity::setEntityName(string entityName){
    this->EntityName = entityName;
}
