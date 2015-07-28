#ifndef ORIGINENTITY_H
#define ORIGINENTITY_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "DataFormatUtil.h"

using namespace std;

class OriginEntity
{

    string EntityName;
    public:

        OriginEntity();

        virtual ~OriginEntity();

        void setEntityName(string entityName);

        virtual void initFromVector(vector<string> mVector) = 0;

        virtual void readNextStream(istream& istr) = 0;

        virtual void readFromString(string str) = 0;

    protected:
    private:
};

#endif // ORIGINENTITY_H
