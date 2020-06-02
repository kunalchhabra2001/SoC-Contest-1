#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b){
	return a>=b;
}
long long int Max_Sum_Generator(long long int *arr, long long int n, long long int k)
{
	// This is equivalent to taking K-1 subarrays having maximum Sum added to the Sum of All the Elements.
	//How?
	// e.g N=8 K=4 arr[8] = 19,-3,-5,-19,-34,-23,76,89
	//max sum always includes 1*(19+.a.) + 2*(.b.) + 3*(.c.) + 4*(.d.) .....8*(89+..h..)
	// Split into 1*(sum of all) + 1*(b+..h)+ (1*c+..h) + 1*(d+...h).....
	// Since all a-h are variables .. We can take max sum of numbers starting from last or finding those K-1 Subarrays whose sum from last is max

	long long int count = k-1,sum = 0,max_sum=0;
	vector<long long int> v;
	for(int i=n-1;i>=0;--i){
		sum += arr[i];
		if(i>0)v.push_back(sum);
	}
	max_sum = sum;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());

	for(int i=0;i<count;++i){
		max_sum += v[i];
	}
	return max_sum;
}

int main(){
	long long int N,K;
	cin >> N >> K;
	long long int arr[N];
	for(int i=0;i<N;i++) cin >> arr[i];
	long long int max_sum = Max_Sum_Generator(arr,N,K);
	cout << max_sum << endl;



}