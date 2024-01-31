#include <iostream>
#include <cmath>

//g++ time_class.cpp -o time_class --std=c++14

using namespace std;

class Time{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hoursVal,int minutesVal,int secondsVal){
        hours = hoursVal;
        minutes = minutesVal;
        seconds = secondsVal;
    }

    int getHours() const{
        return hours;
    }
    int getMinutes() const{
        return minutes;
    }
    int getSeconds() const{
        return seconds;
    }

    void setHours(const int hoursVal) {
        hours = hoursVal;
    }
    void setMinutes(const int minutesVal) {
        minutes = minutesVal;
    }
    void setSeconds(const int secondsVal) {
        seconds = secondsVal;
    }

    void toSeconds(){
        int sum_all_sec = (hours*3600) + (minutes * 60) + seconds;
        cout << endl << sum_all_sec << endl;
    }

    void toHours(){
        int sum_all_hou = 0;
        int buffer = 0;
        if(seconds > 30){
            buffer +=1;
        }
        if(minutes+buffer >30){
            sum_all_hou+=1;
        }
        sum_all_hou += hours;
        cout << endl<<sum_all_hou<<endl;
    }

    void toMinutes(){
        int sum_all_minutes = 0;
        int buffer = 0;
        if(seconds > 30){
            buffer +=1;
        }
        sum_all_minutes = minutes + (hours*60) + buffer;
        cout << endl << sum_all_minutes << endl;
    }

    string tostring(){
        string value_all = (to_string(hours)) + ":" + (to_string(minutes)) + ":" + (to_string(seconds));
        return value_all;
    }

    Time operator +(const Time& other) {
        int sumSec = seconds + other.seconds;
        int sumMin = minutes + other.minutes;
        int sumHou = hours + other.hours;

        sumMin += sumSec / 60;
        sumSec %= 60;
        sumHou += sumMin / 60;
        sumMin %= 60;
        sumHou %= 24;

        return Time(sumHou, sumMin, sumSec);
    }

    Time operator -(const Time& other) {
        int mSec = seconds - other.seconds;
        int mMin = minutes - other.minutes;
        int mHou = hours - other.hours;

        if (mSec < 0){
            mSec += 60;
            mMin--;
        }
        if (mMin < 0){
            mMin += 60;
            mHou--;
        }
        if (mHou < 0){
            mHou += 24;
        }

        return Time(mHou, mMin, mSec);
    }

};

int main(){
    Time t1(18,11,34);
    Time t2(20,55,59);
    Time t3  = t1+t2;
    Time t4 = t1-t2;
    cout << endl << t3.getHours()<< " : "<<t3.getMinutes()<< " : "<< t3.getSeconds() << endl;
    cout << endl << t4.getHours()<< " : "<<t4.getMinutes()<< " : "<< t4.getSeconds() << endl;
    t1.toHours();
    t1.toMinutes();
    t1.toSeconds();
    cout  << endl << t1.tostring();

}