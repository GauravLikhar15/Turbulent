#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int QuickSortPartition(vector<int> &v,int low,int high){    //this arranges pivot element such that all the elements in the right side of the array are smaller than pivot and all the elements at the lest siide greater 
        int initial = low;
        int target = v[low];
        low++;
        while(high > low){
            while(v[low] <= target){low++;}      
            while(v[high] > target){high--;}
            if(low < high){swap(v[low],v[high]);}
        }
        swap(v[high] , v[initial]);
        return high;
    }

    void QuickSortIterator(vector<int> &arr,int low,int high){   //Again the pivot elemeent is chosen then again left and right subarray is sorted with quick sort
        if(low < high){
            int index = QuickSortPartition(arr,low,high);
            QuickSortIterator(arr,low,index - 1);
            QuickSortIterator(arr,index + 1 ,high);
        }
    }
    void QuickSort(vector<int> &arr){QuickSortIterator(arr,0,arr.size() - 1);}
};
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(10);
    v.push_back(2);v.push_back(100);v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);
    Solution S;
    S.QuickSort(v);
    for(int i = 0 ; i < v.size(); i++){
        cout<<v[i]<<"  ";
        }
    return 0;
}
