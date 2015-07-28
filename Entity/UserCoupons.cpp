#include "UserCoupons.h"

UserCoupons::UserCoupons(){
}

UserCoupons::~UserCoupons(){
}

string UserCoupons::GetUserID() {
    return m_UserID;
}

void UserCoupons::SetUserID(string val) {
    m_UserID = val;
}

string UserCoupons::GetCouponList() {
    return m_CouponList;
}

void UserCoupons::SetCouponList(string val) {
    m_CouponList = val;
}

void UserCoupons::SetCouponList(vector<string> couponVector) {
    m_CouponList = JoinVectorItems(couponVector, " ");
}
