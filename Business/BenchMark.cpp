#include "BenchMark.h"

BenchMark::BenchMark()
{
    //ctor
}

BenchMark::~BenchMark()
{
    //dtor
}

void BenchMark::init(string user_list_file, string coupon_area_test_file){
    ifstream ifile_user(user_list_file.c_str());
    CSVIterator loop_user(ifile_user);
    ++loop_user;
    for(; loop_user != CSVIterator(); ++loop_user){
        OriginUser *p_user = new OriginUser();
        p_user->readFromCSVIterator(loop_user);
        this->m_Users.push_back(p_user);
    }
    ifstream ifile_coupon_area(coupon_area_test_file.c_str());
    CSVIterator loop_coupon_area(ifile_coupon_area);
    ++loop_coupon_area;
    for(; loop_coupon_area != CSVIterator(); ++loop_coupon_area){
        OriginCouponArea *p_couponArea = new OriginCouponArea();
        p_couponArea->readFromCSVIterator(loop_coupon_area);
        //this->m_CouponArea.push_back(p_couponArea);
        string smallArea = p_couponArea->GetSmallAreaName();
        string prefArea = p_couponArea->GetPrefName();

        if(this->mp_SmallArea2Coupon.count(smallArea) == 0){
            vector<string> couponVector;
            this->mp_SmallArea2Coupon[smallArea] = couponVector;
        }
        this->mp_SmallArea2Coupon[smallArea].push_back(p_couponArea->GetCouponID());

        if(this->mp_PrefArea2Coupon.count(prefArea) == 0){
            vector<string> couponVector;
            this->mp_PrefArea2Coupon[prefArea] = couponVector;
        }
        this->mp_PrefArea2Coupon[prefArea].push_back(p_couponArea->GetCouponID());
    }
}

vector<UserCoupons*> BenchMark::getRecResult(){
    vector<UserCoupons*> resRetVec;
    if(this->m_Users.size() == 0 || this->mp_SmallArea2Coupon.size() == 0 || this->mp_PrefArea2Coupon.size() == 0)
        return resRetVec;
    for(size_t i = 0; i < m_Users.size(); i++){
        string userID = m_Users[i]->getUserID();
        string userPrefName = m_Users[i]->getPrefName();
        UserCoupons *userCoupon = new UserCoupons();
        vector<string> couponList;
        couponList = this->mp_PrefArea2Coupon[userPrefName];
        userCoupon->SetUserID(userID);
        userCoupon->SetCouponList(couponList);
        resRetVec.push_back(userCoupon);
        //cout << userPrefName << ",   " << couponList.size() << endl;
    }
    return resRetVec;
}
