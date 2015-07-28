#ifndef ORIGINCOUPONAREA_H
#define ORIGINCOUPONAREA_H

#include "OriginEntity.h"


class OriginCouponArea : public OriginEntity
{
    public:

        OriginCouponArea();

        virtual ~OriginCouponArea();

        void initFromVector();

        string GetSmallAreaName();

        void SetSmallAreaName(string val);

        string GetPrefName();

        void SetPrefName(string val);

        string GetCouponID();

        void SetCouponID(string val);

    protected:
    private:

        string m_SmallAreaName;

        string m_PrefName;

        string m_CouponID;
};

#endif // ORIGINCOUPONAREA_H
