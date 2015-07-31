#ifndef TIMEUTIL_H_INCLUDED
#define TIMEUTIL_H_INCLUDED

#include <time.h>
#include <string>
#include <stdio.h>

#define MST (-7)
#define UTC (0)
#define CCT (+8)

#define HMS "hh:mm:ss"
#define YMDHMS "YYYY-MM-DD hh:mm:ss"
using namespace std;

namespace MyUtils{
    namespace time_util{
    inline time_t getCurrentTime(){
        time_t t_now;
        time(&t_now);
        return t_now;
    }

    inline struct tm* getCurrentTime(int time_zone){
        time_t tt_now;
        struct tm *tm_now;

        time(&tt_now);
        tm_now = gmtime(&tt_now);
        tm_now->tm_hour += time_zone;
        return tm_now;
    }

    inline struct tm* cnvrtStr2TM(string time_str, string time_format){
        struct tm *tm_time;
        time_t tt_now = time(NULL);
        tm_time = gmtime(&tt_now);
        tm_time->tm_hour += CCT;
        int year = 0, month = 0, day = 0, hour = 0, minut = 0, second = 0;
        if(time_format == HMS){
            if(3 != sscanf(time_str.c_str(), "%02d:%02d:%02d", &hour, &minut, &second))
                return NULL;
            else{
                tm_time->tm_hour = hour;
                tm_time->tm_min = minut;
                tm_time->tm_sec = second;
            }
        }else if(time_format == YMDHMS){
            if(6 != sscanf(time_str.c_str(), "%04d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &minut, &second)){
                return NULL;
            }else{
                tm_time->tm_year = year - 1900;
                tm_time->tm_mon = month - 1;
                tm_time->tm_mday = day;
                tm_time->tm_hour = hour;
                tm_time->tm_min = minut;
                tm_time->tm_sec = second;
            }
        }
        return tm_time;
    }

    inline time_t cnvrtStr2TT(string time_str, string time_format){
        struct tm *tm_time_ptr = cnvrtStr2TM(time_str, time_format);
        return mktime(tm_time_ptr);
    }

    inline string cnvrtTime2Str(time_t *tt_time){
        string ret(ctime(tt_time));
        return ret;
    }
    inline string cnvrtTime2Str(struct tm *tm_time_ptr){
        string ret(asctime(tm_time_ptr));
        return ret;
    }

    inline long getDiffSecBtwTime(time_t t_begin, time_t t_end){
        return difftime(t_end, t_begin);
    }

    inline int getDiffMinBtwTime(time_t t_begin, time_t t_end){
        return difftime(t_end, t_begin)/60;
    }

    inline int getDiffHourBtwTime(time_t t_begin, time_t t_end){
        return difftime(t_end, t_begin)/3600;
    }

    inline int getDiffDayBtwTime(time_t t_begin, time_t t_end){
        return difftime(t_end, t_begin)/(24*3600);
    }
    }
}

#endif // TIMEUTIL_H_INCLUDED
