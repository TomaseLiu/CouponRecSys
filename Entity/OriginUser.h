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

        void initFromVector();

        string getUserID();

        void setUserID(string userId);

        string getPrefName();

        void setPrefName(string prefName);

        string getSexFemale();

        void setSexFemale(string sexFemale);

        int getAge();

        void setAge(int age);

        string getRegDate();

        void setRegDate(string regDate);

        string getWdwDate();

        void setWdwDate(string wdwDate);

    protected:
    private:
};

#endif // ORIGINUSER_H
