#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

char arr[10000000];
int count;
int c[1000100],d[1000100];

int main()
{
      cin>>arr;
     int n=strlen(arr);
      int f=0,b=0; 
      for(int i=0;i<=n;i++)
       {
         c[i]=INT_MAX;
         d[i]=INT_MAX;
    }
    stack<int> s;
    for(int i=0;i<n;i++)
     {
      if(arr[i]==')')
       {
     if(!s.empty())
     {
      int top=s.top();
      s.pop();
      d[i]=top;
      c[i]=top;// AT LEAST 
        c[i]=min(c[d[i]-1],c[i]);// AS LEFT AS POSSIBLE WILL BE THE LONGEST 
                             //  CHAR AR J-1 CAN BE ( ALSO IN THAT CASE IT WILL  GIVE INT_MAX , SOO                                  // WILL NOT INCLUDED
     
     }
    }
    else s.push(i);
  }
  int ans=0,count=1;
  for(int i=0;i<n;i++)
   {
     if(arr[i]==')')
      {
    if(i-c[i]+1>ans)
         {
       ans=i-c[i]+1;
           count =1;
     }
     else if(i-c[i]+1==ans)
      {
        count ++;
      }
   }
   }
       cout<<ans;
    if(ans==0)
     {
        cout<<" "<<1<<endl;
  }
  else cout<<" "<<count<<endl;
}