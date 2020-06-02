#include<bits/stdc++.h>
using namespace std;

// If XOR of all the A[i]'s is non zero, The one who plays first will win always,, This is because XOR Will return the number of extra moves available
//To the first player to win the game.

void XOR_Finder(long long int A[], int N)
{
	int answer = A[0];
	for(int i=1;i<N;i++){
		answer = answer^A[i];
	}
	if(answer!=0){
		cout << "Gaitonde" << endl;
	}
	else cout << "Isa" << endl;
}


int main()
{
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		long long int A[N];
		for(int i=0;i<N;i++){
			cin >> A[i];
		}
		XOR_Finder(A,N);

	}



}