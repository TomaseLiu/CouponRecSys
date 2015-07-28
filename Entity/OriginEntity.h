#ifndef ORIGINENTITY_H
#define ORIGINENTITY_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "DataFormatUtil.h"
#include "CSVFileUtil.h"

using namespace std;

class OriginEntity
{
    string EntityName;

    public:

        vector<string> mVector;

        OriginEntity();

        virtual ~OriginEntity();

        void setEntityName(string entityName);

        virtual void initFromVector();

        void readNextStream(istream& istr);

        void readFromString(string str);

        void readFromCSVIterator(CSVIterator csvItr);

    protected:
    private:
};

#endif // ORIGINENTITY_H
