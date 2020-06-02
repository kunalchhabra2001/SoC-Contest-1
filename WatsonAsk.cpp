#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int N,count=0;
		cin >> N;
		long long int A[N],B[N];
		for(int i=0;i<N;i++)
		{
			cin >> A[i];
			B[i] = A[i]%10;

		}
		sort(B,B+N);
		for(int i=1;i<N;i++){
			if(count!=0)break;
			else{
				int d = abs(B[i]-B[i-1]);
				if(d>1){
					count++;
					cout << "NO" << endl;
				}	
			}
		}
		if(count==0)cout << "YES" << endl;

	}

}