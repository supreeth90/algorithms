#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    int a,b;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> a >> b;
        int sqrt_a=(int)sqrt(a);
        cout << "sqrt_a" << sqrt_a << endl;
        int start=sqrt_a*sqrt_a;
         cout << "start" << start << endl;
        if(start < a) {
            sqrt_a++;
            start=sqrt_a*sqrt_a;
        }
         cout << "changed start" << start << endl;
        int count=0;
        while(start >= a && start <= b) {
            count ++;
            sqrt_a++;
            start=sqrt_a*sqrt_a;
        }
        cout << count << endl;
    }
    return 0;
}