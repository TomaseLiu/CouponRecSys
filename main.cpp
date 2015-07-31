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
#include "MyHashMapDicUtil.h"

#include "TimeUtil.h"

using namespace std;

int main()
{

    cout << MyUtils::time_util::getCurrentTime() << endl;

    string strTime = "2015-07-31 13:05:09";
    //string timeFromat = "hh:mm:ss";
    string timeFromatYear = "YYYY-MM-DD hh:mm:ss";
    tm *tm_time = MyUtils::time_util::cnvrtStr2TM(strTime, timeFromatYear);

    cout << tm_time->tm_hour << ":" << tm_time->tm_min << endl;
    cout << tm_time->tm_year << "-" << tm_time->tm_mon << "-" << tm_time->tm_mday << endl;

    time_t end_time = tm_time == NULL ? MyUtils::time_util::getCurrentTime() : mktime(tm_time);
    time_t begin_time = MyUtils::time_util::getCurrentTime();

    cout << MyUtils::time_util::getDiffSecBtwTime(begin_time, end_time) << endl;
    cout << MyUtils::time_util::getDiffMinBtwTime(begin_time, end_time) << endl;

    cout << MyUtils::time_util::cnvrtTime2Str(tm_time) << endl;
    cout << "dfad" << endl;
    cout << MyUtils::time_util::cnvrtTime2Str(&begin_time) << endl;


/*! hash dict test
    HashDict hashDict = initHashDictFromFile("./Resource/coupon_list_train.csv", -1);
    cout << hashDict.getSize() << endl;
    cout << hashDict.GetHashStr(101) << endl;
    writeHashDictIntoFile("./coupon_hash_dict.dic", hashDict);
*/
    /*couponAreaList test
    vector<OriginCouponArea*> couponAreaList = readOriginEntityFromFile<OriginCouponArea>("./Resource/coupon_area_test.csv");

    cout << couponAreaList.size() << endl;
    */

    /*couponVisitList test
    vector<OriginCouponVisit*> couponVisitList = readOriginEntityFromFile<OriginCouponVisit>("./Resource/coupon_visit_train.csv");
    cout << couponVisitList.size() << endl;
    cout << couponVisitList[0]->GetDate() << endl;
    */

    /*BenchMark test
    BenchMark *benchMark = new BenchMark();
    benchMark->init("./Resource/user_list.csv", "./Resource/coupon_area_test.csv");

    vector<UserCoupons*> recRet = benchMark->getRecResult();
    cout << recRet.size() << endl;
    writeRecResultIntoCsv("./predict.csv", recRet);
    return 0;
    */
}
