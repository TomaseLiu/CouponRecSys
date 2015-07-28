#ifndef ORIGINUSER_H
#define ORIGINUSER_H

#include "OriginEntity.h"

class OriginUser : public OriginEntity
{
    string UserID;

    string PrefName;

    string SexFemale;

    int Age;

    string RegDate;

    string WdwDate;

    public:

        OriginUser();

        virtual ~OriginUser();

        void initFromVector(vector<string> mVector);

        void readNextStream(istream& istr);

        void readFromString(string str);

    protected:
    private:
};

#endif // ORIGINUSER_H
