#include<bits/stdc++.h>
using namespace std;

int main()
//Since n and m are too large, We can't even store all the numbers
//Binary Search Will help

//Fact used: For a given number,, If no. of entries less than that are greater than K,
//Then Answer lies in lesser than the number

{
	long long int n,m,k;
	cin >> n >> m >> k;
	long long int right_bound = 2*m*n,left_bound=0;
	long long int mid = (left_bound+right_bound)/2,value=0;

	while(left_bound!=right_bound) // O(log(nm))
	{	
		mid = (left_bound+right_bound)/2;
		value = 0; //Keeps the track of number of entries less than mid
		for(int i=1;i<=n;i++)
		{
			value += min(m,mid/i);
		}
		if(value<k){
			// Number of elements are lesser -- Look for bigger answer
			left_bound = mid+1;
		}
		else right_bound = mid;

	}
	cout << left_bound << endl;


}
