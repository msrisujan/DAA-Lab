#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

float logx(double n){
    double num, mul, cal, sum = 0;
    num = (n - 1) / (n + 1);

    for (int i = 1; i <= 1000; i++) {
        mul = (2 * i) - 1;
        cal = pow(num, mul);
        cal = cal / mul;
        sum = sum + cal;
    }
    sum = 2 * sum;
    return sum;
}
int main(){
    int n;
    cin>>n;
    float x;
    x = logx(n);
    float m = x/ logx(3);
    m *= 10000;
    int res = floor(m);
    float ans = res/10000.00;
    cout<<ans;
}