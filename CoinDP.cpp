//Using DP Algorithm
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(int coins[],int size, int amount) {
        int dp[size+1][amount+1];
        for(int i = 0 ;i<=amount;i++)
        {dp[0][i] = INT_MAX-1;}
        
        for(int i = 0;i<=size;i++)//all values put to zero
        {dp[i][0] = 0;}
        
        for(int j =1;j<=amount;j++){//coins are shortened
          if(j%coins[0]==0)
          {
            dp[1][j] = j/coins[0];
            continue;
          }
            dp[1][j] = INT_MAX-1;
        }
        for(int i = 2;i<=size;i++){//Prev values are copied ,
          for(int j = 1;j<=amount;j++)
          {
            if(coins[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
              dp[i][j] = min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
            }
          }
        }
      
      if(dp[size][amount]==INT_MAX-1)return -1;
      
      return dp[size][amount];
    }
};
int main()
{
	Solution temp;
	int size;
	cout<<"Enter the No of Coins : ";
	cin>>size;
	int coins[size+1];
	for(int i = 0;i<size;i++)
	{
		int t;
		cin>>t;
		coins[i] = t;
	}
	sort(coins,coins+size);
	int amount;
	cout<<"Enter the cost you want : ";
	cin>>amount;
	cout<<"Minimum number of coins required are :  "<<temp.coinChange(coins,size,amount)<<endl;
	return 0;
}
