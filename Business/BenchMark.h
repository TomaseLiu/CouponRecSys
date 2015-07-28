#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "OriginUser.h"
#include "OriginCouponArea.h"
#include "UserCoupons.h"

#include "CSVFileUtil.h"
#include "DataFormatUtil.h"

#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class BenchMark
{
    vector<OriginUser*> m_Users;

    //vector<OriginCouponArea*> m_CouponArea;

    map<string, vector<string> > mp_SmallArea2Coupon;

    map<string, vector<string> > mp_PrefArea2Coupon;

    public:

        BenchMark();

        virtual ~BenchMark();

        void init(string user_list_file, string coupon_area_test_file);

        vector<UserCoupons*> getRecResult();

    protected:
    private:
};

#endif // BENCHMARK_H
