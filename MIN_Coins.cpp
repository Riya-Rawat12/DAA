// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = minCoins(coins, m, V-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}

return res;
}

// Driver program to test above function
int main()
{
	int m;
    cin>>m;
    int coins[m];
    for(int i=0;i<m;i++)
    {
        cin>>coins[i];
    }

    int V;
    cin>>V;
	cout << "Minimum coins required is :";
	int result=minCoins(coins,m,V);
    if(result==INT_MAX)
    {
        cout<<"NO coins are there";
    }
    else
    {
        cout<<result;
    }
	return 0;
}
