#include "OriginCouponArea.h"

OriginCouponArea::OriginCouponArea()
{
    //ctor
}

OriginCouponArea::~OriginCouponArea()
{
    //dtor
}
void OriginCouponArea::initFromVector(){
    if(this->mVector.size() == 3){
        this->m_SmallAreaName = convert<string>(this->mVector[0]);
        this->m_PrefName = convert<string>(this->mVector[1]);
        this->m_CouponID = convert<string>(this->mVector[2]);
        //cout << m_PrefName << " " << m_CouponID << endl;
    }
}

string OriginCouponArea::GetSmallAreaName() {
    return m_SmallAreaName;
}
void OriginCouponArea::SetSmallAreaName(string val) {
    m_SmallAreaName = val;
}
string OriginCouponArea::GetPrefName() {
    return m_PrefName;
}
void OriginCouponArea::SetPrefName(string val) {
    m_PrefName = val;
}
string OriginCouponArea::GetCouponID() {
    return m_CouponID;
}
void OriginCouponArea::SetCouponID(string val) {
    m_CouponID = val;
}
