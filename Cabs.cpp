#include<bits/stdc++.h>
using namespace std;
/*
sample input

6
1 0 2 0
16 0 21 30
9 30 13 0
21 30 22 30
21 30 22 30
12 0 12 30
*/
int main()
{
	int n;
	cout<<"Enter The Total No of Passenger: ";
	cin>>n;
	int tot_min = 24*60;
	int timeline[tot_min];   //per min array
	for(int i = 0; i<=tot_min;i++)
	{timeline[i] = 0;}      //values are set to zero
	for(int i = 0; i<n;	i++)
	{
		// int h1,m1,h2,m2;
		// cin>>h1>>m1>>h2>>m2;
		// h1*=60;
		// h2*=60;
		// h1+=m1;
		// h2+=m2;

		int h1,h2;
		cout<<"Enter The Start Time of Passenger "<<(i + 1)<<":\t";
		cin>>h1;
		cout<<"Enter The End Time of Passenger "<<(i + 1)<<":\t";
		cin>>h2;
		for(int k = h1;k<=h2;k++){timeline[k]+=1;}    //Overlap
	}
	int ans = 0;
	for(int i = 0;i<tot_min;i++)
	{ans = max(ans,timeline[i]);}
	cout<<ans<<endl;
	return 0;
}
