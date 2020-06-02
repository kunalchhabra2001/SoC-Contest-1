#include<bits/stdc++.h>
using namespace std;

// Similiar to GameOfBullets prob, Just we have to carve out the numbers to be XORed
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int count=0,ans=0;
		int N=s.length();
		int i=0;
		for(i=0;i<N;i++)
		{
			if(s[i]=='W')break;
			else count++;
		}
		if(count==(N-1-count))cout << "Chef" << endl;
		else cout << "Aleksa" << endl;
	}





}