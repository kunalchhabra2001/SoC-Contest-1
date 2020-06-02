#include<bits/stdc++.h>
using namespace std;


// A structure is needed for each teacher to improve our input characteristics
struct Trainer
{
	long long int date,time,sadness;
};

// A bool comparator is needed to arange the days of the trainers in increasing order
bool comparator(struct Trainer a,struct Trainer b)
{
	return a.date < b.date;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		struct Trainer arr[100001]={0,0,0}; //Stores the max value of date,trainers,sadness
		long long int N,D;
		priority_queue <pair<long long int, long long int>> sad_checker; //Will prioiritize the max sadness for us
		pair<long long int,long long int> var; //Keeps a track of the trainer to be added for the final answer
		cin >> N >> D;
		for(int i=0;i<N;i++){
			cin >> arr[i].date >> arr[i].time >> arr[i].sadness;
		}
		long long int j=0; // Keeps a track of every person
		sort(arr,arr+N,comparator); // We get a sorted list of trainers according to their joining dates
		for(int i=1;i<=D;i++)
		{
			while(j<N && arr[j].date==i)
			{
				sad_checker.push(make_pair(arr[j].sadness,arr[j].time));
				j++;
			}
		

			if(!sad_checker.empty())
			{
				var = sad_checker.top();
				sad_checker.pop();
				var.second--; // Tine decreases by one
				if(var.second!=0)sad_checker.push(var);
			}
		}
		long long int sol = 0; //The final answer
		while(!sad_checker.empty())
		{
			var = sad_checker.top();
			sad_checker.pop();
			sol += (var.first)*(var.second);

		}

		cout << sol << endl;



	}
}