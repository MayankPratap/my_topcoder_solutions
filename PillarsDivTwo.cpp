#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define oo 1000000000

typedef long long ll;
typedef long double ld;


const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;

int n;
//double dp[105][55];


double solve(vector<int>height,int prevheight,int curpillar,int w){

   if(curpillar>=n)
       return 0;

   else{

       double sum=0;

       double res;

     //  printf("%d\n",dp[prevheight][curpillar]);

     //  if(dp[prevheight][curpillar]!=-1)
       //	  return dp[prevheight][curpillar];

       for(int i=1;i<=height[curpillar];++i){

           res=(prevheight-i)*(prevheight-i)+w*w;
           res=sqrt(res);

           sum=max(sum,res+solve(height,i,curpillar+1,w));
       }

       return sum;
   }

}

double maximalLength(vector<int>height,int w){

    double sum=0;

    n=height.size();

   // memset(dp,-1.0,sizeof(dp));


    for(int i=1;i<=height[0];++i){

        sum=max(sum,solve(height,i,1,w));
    }

    return sum;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);  

    vector<int>height(50);
    int w;

    int n;
    cin>>n;

  
    for(int i=0;i<n;++i)
    	cin>>height[i];

    cin>>w;

    printf("%0.15lf\n",maximalLength(height,w));

	return 0;
}
