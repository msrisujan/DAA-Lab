#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout<<"*"<<endl;
        return 0;
    }
    int a[n];
    int b[n];
    for(int j = 0; j < n; j++){
        cin>>a[j];
        b[j] = a[j];
    }
    sort(b, b + n);
    int x = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            x = 1;
        }
    }
    if(x == 0){
        cout<<"*"<<endl;
        return 0;
    }
    int start = 0;
    int end = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(b[i] != a[i]){
            if(count == 0){
                start = i;
                count = 1;
            }
            else{
                end = i;
            }
        }
    }
    cout<<start<<endl<<end<<endl;
}