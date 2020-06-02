#include<bits/stdc++.h>
using namespace std;


long long int MaxArea(long long int *arr,long long int n)
{
	long long int max_area=0; // Stores the max area to be returned
	stack<long long int> s; //Stores the histograms until required
	long long int tp=0; //Stores the top index of stack
	long long int Area = 0; //Stores Area of each histo
	long long int i=0;

	while(i < n)
	{

		if(s.empty() || arr[s.top()] <= arr[i]){
			s.push(i++);
		}
		else{
			tp = s.top();
			s.pop(); // So that Next Rectangle is available for computation
			Area = arr[tp] * (s.empty() ? i: i-s.top()-1);

			//Check for max area
			if(max_area < Area)max_area=Area;



		}




	}
	// Now we have the stack of all remaining bars

	while(!s.empty())
	{
		tp=s.top();
		s.pop(); // So that Next Rectangle is available for computation
			Area = arr[tp] * (s.empty() ? i: i-s.top()-1);

			//Check for max area
			if(max_area < Area)max_area=Area;

	}
	return max_area;

}


int main(){

	long long int N;
	while(N!=0){
	cin >> N;
	if(N!=0){long long int arr[N];
	for(long long int i=0;i<N;i++) cin >>	arr[i];
	long long int Max = MaxArea(arr,N);
	cout << Max << endl;
	}
	}
}