#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high)
{

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

int partition_median(int array[], int low, int high, int p)
{

  int pivot = p;

  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[high]);

  return (i + 1);
}

void quickSort_median(int array[], int low, int high, int p)
{
  if (low < high)
  {

    int pi = partition_median(array, low, high, p);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

int pivot(int nums[], int low, int high, int m)
{
    int prev = low;
    //int run = low;
    //int last = high - 1;

    while(low <= high)
    {
        if(nums[low] == m)
        {
            low++;
        }
        else if(nums[low] < m)
        {
            swap(nums[low],nums[prev]);
            prev++;
            low++;
        }
        else
        {
            swap(nums[low],nums[high]);
            high--;
        }
    }
    return prev;
}

int Median(int nums[], int k, int low, int high)
{
    if(high - low <= 10)
    {
        sort(nums + low, nums + high);
        return nums[low + k - 1];
    }

    int med = ceil((high - low + 1)/5);
    int medians[med];
    int medianIndex = 0;

    for(int i = low; i < high; i+=5)
    {

        if(high - i <= 10)
        {
            sort(nums + i, nums + high);
            medians[medianIndex] = nums[(high + i)/2];
        }
        else
        {
            sort(nums + i, nums + i + 5);
            medians[medianIndex] = nums[i + 2];
        }
        medianIndex++;
    }

    int median = Median(medians, (medianIndex-1)/2 + 1, 0,medianIndex - 1);
    int p = pivot(nums, low, high, median);

    if(p - low + 1 == k)
    {
        //return nums[p];
        return p;
    }

    if(p - low + 1 > k)
    {
        return Median(nums, k, low, p);
    }

    return Median(nums,k - (p - low + 1), p + 1, high);
}

int findMedian(int nums[], int k, int size)
{
    return Median(nums, size - k + 1, 0, size);
}

long int random()
{
	int num=rand()%10000000;
	return num;
}

int main()
{
	int num,rd;

    struct timespec start, end;

    srand(time(0));
    int ch,a=1;
    /*cout<<"\nEnter Array size is : ";
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        rd=random();
        cout<<"\t "<<rd;
        arr[i] = rd;
    }*/
    //int arr[25] = {8,33,17,51,57,49,35,11,25,37,14,3,2,13,52,12,6,29,32,54,5,16,22,23,7};
    //int arr[9] = {1,2,3,4,5,1000,8,9,99};
    //int arr[20]={2,4,6,8,10,1,3,9,5,7,11,13,19,15,17,12,14,16,20,18};

    //int arr[10]={51,60,52,58,55,57,54,53,56,59};

    int arr[14]={21,30,22,28,23,27,28,26,25,29,31,35,33,32};

    //int arr[25]={1,25,2,24,3,22,4,21,5,20,6,19,13,18,6,17,8,16,9,15,10,14,11,7,12};

    cout<<endl;
    for(int i=0;i<14;i++)
    {
        cout<<arr[i]<<" ";
    }
        cout<<"Median of Medians algorithm";
        
        int n = sizeof(arr)/ sizeof(arr[0]);

        

           

                    int k = findMedian(arr, n/2 + 1, n-1);

                    ios_base::sync_with_stdio(false);

                    quickSort_median(arr, 0, n-1, k);
                    //int k = findMedian(arr, n/2 + 1, n);

                    

                    // Calculating total time taken by the program.
                   

                    cout << "\nMedian is : "<<k;
                    cout << "\nSorted array : \n";
                    printArray(arr, n);
        cout<<"\nDo you want to continue(1/0) : ";
        cin>>a;
    

	return 0;
}