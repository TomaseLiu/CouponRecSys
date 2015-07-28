#ifndef USERCOUPONS_H
#define USERCOUPONS_H

#include <vector>
#include <string>

#include "DataFormatUtil.h"

using namespace std;

class UserCoupons
{
    public:
        UserCoupons();

        virtual ~UserCoupons();

        string GetUserID();

        void SetUserID(string val);

        string GetCouponList();

        void SetCouponList(string val);

        void SetCouponList(vector<string> couponVector);

    protected:
    private:
        string m_UserID;
        string m_CouponList;
};

#endif // USERCOUPONS_H
