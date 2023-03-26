#include <bits/stdc++.h>
using namespace std;

int Count = 0;
void subset(int* a,int* bit,int n,int index){
    bit[index] += 1;
    for(int i = n-1;i>=0;i--){
        if(bit[i] > 1){
            bit[i] -= 2;
            bit[i-1] += 1;
        }
    }
    cout<<"{ ";
    for(int i = 0;i<n;i++){
        if(bit[i] == 1){
            cout<<a[i]<<" ";
        }
    }
    Count++;
    cout<<"}";
    cout<<endl;
    int flag = 0;
    for(int i = 0;i<n;i++){
        if(bit[i] == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        return;
    }
    subset(a,bit,n,n-1);
}


int main(){
    int size;
    cout<<"Enter the size of set: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements of set"<<endl;
    for(int i = 0;i<size;i++) {
        cin>>arr[i];
    }
    int bitCounter[size];
    for(int i = 0;i<size;i++){
        bitCounter[i] = 0;
    }
    cout<<"Empty Set"<<endl;
    subset(arr,bitCounter,size,size-1);
    cout<<"Total Number of subsets are: "<<Count+1<<endl;

}