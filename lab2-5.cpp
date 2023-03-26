#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp;

void binary_search(int arr[], int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (mid == arr[mid])
            temp.push_back(mid);           
        if (mid + 1 <= arr[high])
            binary_search(arr, (mid + 1), high);
        if (mid - 1 >= arr[low])
            binary_search(arr, low, (mid - 1));
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    binary_search(arr,0,n-1);
    if(temp.size() == 0)
    {
        cout << "*" << endl;
        return 0;
    }
    sort(temp.begin(),temp.end());
    for(int i : temp)
        cout << i << endl;
}