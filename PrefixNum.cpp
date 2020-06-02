#include<bits/stdc++.h>
using namespace std;

#define longnum 1000000000000000000 // 10^18
int main()
{
	long long int T;
	cin >> T;
	while(T--)
	{
		long long int x , y;
		cin >> x >> y;
		long long int divider = 1; //Maintains the answer to our prob
		long long int flag = 0; // Will Act as an indicator
		long long int answer = -1; // Initializing our final answer
		for(long long int i=x;i<=longnum;i=i*10)
		{
			if(flag!=0)break; // Breaking condition
			else{
				long long int same=i;
				long long int begin = (same/y)*y; // Gives the lower bound 
				while(true)
				{
					if(begin!=0 && begin/divider == x &&  begin%y==0){
						flag = 1;
						answer = begin; // Here's  the answer
						break;
					}
					if(begin/divider!=x && begin>same){
						break; // Look for next digit number
					}
					begin += y; //Moves to the next multiple of y for that i;
					if(begin>longnum) break; //Condition for -1

				}

			}
			divider = divider*10; // So that begin/divider less than 10 always

		}
		cout << answer << endl;

	}



}