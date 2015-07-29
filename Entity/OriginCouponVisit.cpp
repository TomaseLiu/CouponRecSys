#include "OriginCouponVisit.h"

OriginCouponVisit::OriginCouponVisit(){
}

OriginCouponVisit::~OriginCouponVisit(){
}

void OriginCouponVisit::initFromVector(){
    if(this->mVector.size() == 8){
        this->m_PurchaseFlg = convert<bool>(this->mVector[0]);
        this->m_Date = convert<string>(this->mVector[1]);
        this->m_PageSerial = convert<int>(this->mVector[2]);
        this->m_PREFERRER_hash = convert<string>(this->mVector[3]);
        this->m_ViewCouponHash = convert<string>(this->mVector[4]);
        this->m_UserIDHash = convert<string>(this->mVector[5]);
        this->m_SessionIDHash = convert<string>(this->mVector[6]);
        this->m_PurchaseIDHash = convert<string>(this->mVector[7]);
    }
}

bool OriginCouponVisit::GetPurchaseFlg() {
    return m_PurchaseFlg;
}
void OriginCouponVisit::SetPurchaseFlg(bool val) {
    m_PurchaseFlg = val;
}
string OriginCouponVisit::GetDate() {
    return m_Date;
}
void OriginCouponVisit::SetDate(string val) {
    m_Date = val;
}
int OriginCouponVisit::GetPageSerial() {
    return m_PageSerial;
}
void OriginCouponVisit::SetPageSerial(int val) {
    m_PageSerial = val;
}
string OriginCouponVisit::GetPREFERRER_hash() {
    return m_PREFERRER_hash;
}
void OriginCouponVisit::SetPREFERRER_hash(string val) {
    m_PREFERRER_hash = val;
}
string OriginCouponVisit::GetViewCouponHash() {
    return m_ViewCouponHash;
}
void OriginCouponVisit::SetViewCouponHash(string val) {
    m_ViewCouponHash = val;
}
string OriginCouponVisit::GetUserIDHash() {
    return m_UserIDHash;
}
void OriginCouponVisit::SetUserIDHash(string val) {
    m_UserIDHash = val;
}
string OriginCouponVisit::GetSessionIDHash() {
    return m_SessionIDHash;
}
void OriginCouponVisit::SetSessionIDHash(string val) {
    m_SessionIDHash = val;
}
string OriginCouponVisit::GetPurchaseIDHash() {
    return m_PurchaseIDHash;
}
void OriginCouponVisit::SetPurchaseIDHash(string val) {
    m_PurchaseIDHash = val;
}
