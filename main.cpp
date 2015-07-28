#include <iostream>
#include "CSVFileUtil.h"
#include "DataFormatUtil.h"
#include "OriginUser.h"
#include "BenchMark.h"
#include "UserCoupons.h"
#include "MyFileWriter.h"

using namespace std;

int main()
{
    BenchMark *benchMark = new BenchMark();
    benchMark->init("./Resource/user_list.csv", "./Resource/coupon_area_test.csv");

    vector<UserCoupons*> recRet = benchMark->getRecResult();
    cout << recRet.size() << endl;
    writeRecResultIntoCsv("./predict.csv", recRet);
    return 0;
}
