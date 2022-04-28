#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int LinearSearch(vector<int> arr,int target){
            for(int i = 0 ; i < arr.size() ; i++)
            {if(arr[i] == target){return i;}}
            return -1;
        }
        int BinarySearch(vector<int> arr,int target){
            sort(arr.begin(),arr.end());
            int start = 0;
            int end = arr.size() - 1;
            while(start <= end){
                int mid = (start + end)/2;
                if(arr[mid] == target){return mid;}
                else if(arr[mid] < target){start = mid + 1; }
                else if(arr[mid] > target){end = mid - 1;}
            }
            return -1;
        }
};
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(10);
    v.push_back(2);v.push_back(100);v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);
    Solution S;
    cout<<S.LinearSearch(v,100);
    cout<<S.BinarySearch(v,10);
    return 0;
}
