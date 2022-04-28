//Enter the number of nodes -> 4
//Enter the distance between 1 to 2 -> 16
//Enter the distance between 1 to 3 -> 11
//Enter the distance between 1 to 4 -> 6
//Enter the distance between 2 to 1 -> 8
//Enter the distance between 2 to 3 -> 13
//Enter the distance between 2 to 4 -> 16
//Enter the distance between 3 to 1 -> 4
//Enter the distance between 3 to 2 -> 7
//Enter the distance between 3 to 4 -> 9
//Enter the distance between 4 to 1 -> 5
//Enter the distance between 4 to 2 -> 12
//Enter the distance between 4 to 3 -> 2
//
// The Minimum cost is 23


#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void tsp(int curr,int cost,int temp[],int size,int &ans)
{
	if(size==1)  ///Base condition
	{										
		cost+=dp[curr][temp[0]];
		cost+=dp[temp[0]][0];
		ans = min(cost,ans);
		return ;
	}
	for(int i = 0;i<size;i++)    //Jato ani yetoy ahe 
	
	{
		int t1[1001];
		int l = 0;
		for(int j = 0 ;j<size;j++)
		{
			if(i!=j)  //checking if the traversal do not overlap each other 
			{
				t1[l] = temp[j];
				l+=1;
			}
		}
		tsp(temp[i],cost+dp[curr][temp[i]],t1,size-1,ans);	
	}
}
int main()
{
	int nodes;
	cout<<"Enter the number of nodes -> ";
	cin>>nodes;
	for(int i = 0;i<=1000;i++)    //Intially all set to 0
	{
		for(int j = 0;j<=1000;j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 0; i<nodes;i++)   //Input the distance
	{
		for(int j = 0;j<nodes;j++)
		{
			if(i==j)
			{
				continue;
			}
			cout<<"Enter the distance between "<<i+1<<" to "<<j+1<<" -> ";
			cin>>dp[i][j];
		}
	}
	int ans = INT_MAX;
	int temp[nodes];
	for(int i = 1;i<nodes;i++)
	{
		temp[i-1] = i;
	}
	tsp(0,0,temp,nodes-1,ans);
	cout<<"\n The Minimum cost is "<<ans;
}

