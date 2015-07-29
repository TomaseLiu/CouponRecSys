#include <iostream>
#include "CSVFileUtil.h"
#include "DataFormatUtil.h"
#include "OriginUser.h"
#include "BenchMark.h"
#include "UserCoupons.h"
#include "OriginCouponArea.h"
#include "OriginCouponVisit.h"

#include "MyFileWriter.h"
#include "MyFileReader.h"

using namespace std;

int main()
{
    vector<OriginCouponArea*> couponAreaList = readOriginEntityFromFile<OriginCouponArea>("./Resource/coupon_area_test.csv");

    cout << couponAreaList.size() << endl;

    vector<OriginCouponVisit*> couponVisitList = readOriginEntityFromFile<OriginCouponVisit>("./Resource/coupon_visit_train.csv");
    cout << couponVisitList.size() << endl;
    cout << couponVisitList[0]->GetDate() << endl;

    /*
    BenchMark *benchMark = new BenchMark();
    benchMark->init("./Resource/user_list.csv", "./Resource/coupon_area_test.csv");

    vector<UserCoupons*> recRet = benchMark->getRecResult();
    cout << recRet.size() << endl;
    writeRecResultIntoCsv("./predict.csv", recRet);
    return 0;
    */
}
