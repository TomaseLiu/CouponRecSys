#ifndef ORIGINCOUPONVISIT_H
#define ORIGINCOUPONVISIT_H

#include "OriginEntity.h"


class OriginCouponVisit : public OriginEntity
{
    public:
        OriginCouponVisit();

        virtual ~OriginCouponVisit();

        void initFromVector();

        bool GetPurchaseFlg();

        void SetPurchaseFlg(bool val);

        string GetDate();

        void SetDate(string val);

        int GetPageSerial();

        void SetPageSerial(int val);

        string GetPREFERRER_hash();

        void SetPREFERRER_hash(string val);

        string GetViewCouponHash();

        void SetViewCouponHash(string val);

        string GetUserIDHash();

        void SetUserIDHash(string val);

        string GetSessionIDHash();

        void SetSessionIDHash(string val);

        string GetPurchaseIDHash();

        void SetPurchaseIDHash(string val);

    protected:
    private:

        bool m_PurchaseFlg;

        string m_Date;

        int m_PageSerial;

        string m_PREFERRER_hash;

        string m_ViewCouponHash;

        string m_UserIDHash;

        string m_SessionIDHash;

        string m_PurchaseIDHash;
};

#endif // ORIGINCOUPONVISIT_H
