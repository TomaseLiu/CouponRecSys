#ifndef MYFILEWRITER_H_INCLUDED
#define MYFILEWRITER_H_INCLUDED

#include <fstream>
#include <string>
#include "UserCoupons.h"

using namespace std;

void inline writeRecResultIntoCsv(string filePath, vector<UserCoupons*> userCoupons){
    string header = "USER_ID_hash,PURCHASED_COUPONS";
    ofstream ofile(filePath.c_str());
    ofile << header << endl;
    for(size_t i = 0; i < userCoupons.size(); i++){
        string userID = userCoupons[i]->GetUserID();
        string coupons = userCoupons[i]->GetCouponList();
        string result = userID + "," + coupons;
        ofile << result << endl;
    }
    ofile.close();
}


#endif // MYFILEWRITER_H_INCLUDED
