#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void MergeSingleArray(vector<int> &arr,int low,int mid,int high){//Merge single array having two sorted arrays
        vector<int> result;
        int i = low;
        int j = mid+1;
        while(i <= mid && j <= high){
            if(arr[i] < arr[j]){
                result.push_back(arr[i]);
                i++;    
            }else{
                result.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){result.push_back(arr[i]);i++;}
        while(j<=high){result.push_back(arr[j]);j++;}
        arr = result;
    }
    void MergeSortIterator(vector<int> &arr,int low,int high){//calculate mid,merges
        if(low < high){
            int mid = ((low + high)/2);
            MergeSortIterator(arr,low,mid);
            MergeSortIterator(arr,mid+1,high);
            MergeSingleArray(arr,low,mid,high);
        }
    }
};
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(10);
    v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);v.push_back(2);
    Solution S;
    S.MergeSortIterator(v,0,(v.size()-1));
   for(int i = 0 ; i < v.size(); i++){
        cout<<v[i]<<"  ";
        }
    return 0;
}
