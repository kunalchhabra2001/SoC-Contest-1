#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{	
		long long int N;
		cin >> N;
		string s;
		cin >> s;
		long long int count=0;
		int i=0;
		if(s[0]=='R'){
			if(s[1]=='B'){
						count++;
						s[1]='1';
						
			}

		}
		if(s[N-1]=='R'){
			if(s[N-2]=='B'){
						count++;
						s[N-2]='1';
			}
		}
		i=1;
		while(i<N-1){
					if(s[i]=='R'){
					if(s[i-1]=='B' && s[i+1]!='B'){
						count++;
						s[i-1]='1';
					}
					if(s[i-1]!='B' && s[i+1]=='B'){
						count++;
						s[i+1]='1';
					}
					if(s[i-1]=='B' && s[i+1]=='B'){
						count++;
						s[i-1]='1';
					}
					
					}
					i++;

				}
		cout << count << endl;

	}



}