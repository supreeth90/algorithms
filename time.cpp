#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    size_t found;
    int hours;
    string time;
    string newtime;
    cin >> time;
    found=time.find("AM");
    newtime=time.substr(0,8);
    hours=atoi((time.substr(0,2)).c_str());
     if(found != string::npos) {
     	if(hours == 12) {
     		hours=0;
     	} 
     } else {
     	if(hours != 12) {
     		hours=hours+12;
     	} 
     }
     if(hours < 10) {
     	newtime=newtime.replace(0,1,"0");
     	newtime=newtime.replace(1,1,to_string(hours));
     } else {
     	newtime=newtime.replace(0,2,to_string(hours));
     }
     cout << newtime;
    return 0;
}