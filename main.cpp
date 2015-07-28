#include <iostream>
#include "Util/CSVFileUtil.h"
#include "Util/DataFormatUtil.h"

using namespace std;

int main()
{
    std::ifstream       file("./Resource/coupon_area_test.csv");
    std::ofstream       ofile("./test.csv");




    CSVRow row;
    row.readNextRow(file);
    ofile << row << endl;

    string a("hahah,whats,up");
    int b = 123;
    Append2String(a, b);
    cout << a << endl;

    vector<string> cv = split(a, ",");
    cout << cv.size() << endl;
    for(size_t i = 0; i < cv.size(); i++){
        cout << cv[i] << endl;
    }

    int bb = 0;
    string aa = "11";
    bb = convert<int>(aa);
    cout << bb << endl;
    for(CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        string small_area_name = (*loop)[0];
        string pref_name = (*loop)[1];
        string coupon_id_hash = (*loop)[2];

        stringstream ss;
        string sRow;
        Append2String(sRow, small_area_name, ss);
        Append2String(sRow, pref_name, ss);
        Append2String(sRow, coupon_id_hash, ss);
        CSVRow csvRow;
        ss >> csvRow;
        ofile << csvRow << endl;
    }
    //ofile.close();

    cout << "hello world" << endl;
    return 0;
}
