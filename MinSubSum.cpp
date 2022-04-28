#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter Array Size -> ";
	cin>>size;
	int arr[size];
	for(int i = 0 ;i<size;i++)
	{
		cin>>arr[i];
	}
	int ans = INT_MAX;
	for(int i = 0 ;i<size;i++)
	{
		int sum = 0;
		for(int j = i;j<size;j++)
		{
			sum+=arr[j];
			ans = min(ans,sum);	
		}
	}
	cout<<"Minimum Subarray Sum is  -> "<<ans<<endl;
	return 0;
}
