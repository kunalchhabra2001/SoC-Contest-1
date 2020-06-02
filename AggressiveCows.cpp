#include<bits/stdc++.h>
using namespace std;


// Concept : If say min is the minimum distance,, Then all cows with diff <=min can always be placed likewise.. 


bool check_for_k(long long int *stalls, long long int num, long long int reqd_cows,long long int N)
// Will check if num satisfies the condition

{
	long long int cows_count = 1, init = stalls[0];
	for(int i=1;i<N;i++)
	{
		if(stalls[i]-init >= num)
		{
			init = stalls[i];
			cows_count++;
			if(cows_count == reqd_cows){
				return true;
		}

		}
	}
	return false;


}

long long int Search_Func(long long int *stalls, long long int reqd_cows,long long int N)
// Will check in logN time whether Another K greater than previous satisfies the above condition

{
	long long int start = stalls[0], end = stalls[N-1];
	long long int answer = -1;
	long long int mid = (start+end)/2;
	while(start<end)
	{
		mid = (start+end)/2;
		if(check_for_k(stalls,mid,reqd_cows,N))
		{
			answer = max(mid,answer);
			start = mid+1; // To half the check of binary search in 2nd part;

		}
		else end = mid; // To find a lesser k in first halk
	}
	return answer;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int N,C;
		cin >> N >> C;
		long long int stalls[N];
		for(int i=0;i<N;i++) cin >> stalls[i];
		sort(stalls,stalls+N);
		long long int answer = Search_Func(stalls,C,N);
		cout << answer << endl;
	}

}