#include<iostream>
#include <algorithm>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         if(l==r || l>r)
         {
             return ;
         }
         int left[m-l+1];
         int right[r-m+1];
      
         
         for(int i = l;i<=m;i++)left[i-l] = arr[i];
         
         for(int i = m+1;i<=r;i++)right[i-m-1] = arr[i];
         
         int k = l;
         int s1 = m-l+1;
         int s2 = r-m;
         int ii = 0;
         int jj = 0;
         while(ii<s1 && jj<s2)
         {
             if(left[ii]>=right[jj])
             {
                 arr[k] = right[jj];
                 jj+=1;
             }
             else
             {
                 arr[k] = left[ii];
                 ii+=1;
             }
             k+=1;
         }
         while(ii<s1)
         {
              arr[k] = left[ii];
                 ii+=1;
             k+=1;
         }
         while(jj<s2)
         {
               arr[k] = right[jj];
                 jj+=1;
                 k+=1;
         }
    }
    public:
     void mergeSort(int arr[], int l, int r)
    {
       if(l>=r)return;
       
       int mid = (l+r)/2;
       mergeSort(arr,l,mid);
       mergeSort(arr,mid+1,r);
       merge(arr,l,mid,r);
    }
   
};

// { Driver Code Starts.


int main()
{
    int n,T,i;
    cout<<"\nPlease Enter the size : ";
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      arr[i]=rand()%n+1;

      printArray(arr, n);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
      printArray(arr, n);
    return 0;
}  // } Driver Code Ends