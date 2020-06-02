#include<bits/stdc++.h>
using namespace std;

bool Check_For_Palindrome(string s,long long int N)
{	
	int i=0;
	for(i=0;i<=N/2;i++){
		if(s[i]!=s[N-1-i])return false;
	}	
	return true;
}


long long int Num_calc(string s, long long int N)
{
	long long count = 0,limit=0;
	if(Check_For_Palindrome(s,N)){
		if(N%2==0){
			count=3;
			for(int i=N/2-1;i>0;i--){
				if(s[i]!=s[i-1])break;
				count = count+2;
			}
			return count;
		}
		else{
			count = 2;
			for(int i=N/2;i>0;i--){
				if(s[i]!=s[i-1])break;
				count = count+2;
			}
			return count;
		}

	}
	else{
		long long int i=0,j=N-1,answer=0,count=0,checker;
		while(s[i]==s[j]){
			i++,j--;
		}
		string s1 = s[j] + s.substr(i,j-i+1);
		string s2 = s.substr(i,j-i+1)+s[i];
		if(Check_For_Palindrome(s1,s1.length())){
			count = 0;
			checker = s[j];
			for(int k = i-1;k>=0;k--){
				if(s[k]!=checker)break;
				else count++;
			}
			answer += count+1;
		}
		
		if(Check_For_Palindrome(s2,s2.length())){
			checker = s[i];
			count=0;
			for(int k = j+1;k<N;k++){
				if(s[k]!=checker)break;
				else count++;
			}
			answer += count+1;
		}
		
		return answer;
	}
	

}

int main()
{	
	int T;
	cin >> T;
	while(T--){


		string s;
		cin >> s;
		long long int N=s.size();
		cout << Num_calc(s,N) << endl;
	}
}