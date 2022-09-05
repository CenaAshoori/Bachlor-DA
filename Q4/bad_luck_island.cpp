#include<iostream>

using namespace std;
double dp[100][100][100];

int tamrin8()
{
	int rock,scissor,paper;
	cin>>rock>>scissor>>paper;

	dp[rock][scissor][paper]=1;
	int r,s,p;
	for(r=rock;r>=0;r--)
		for(s=scissor;s>=0;s--)
			for(p=paper;p>=0;p--)
				if((r>0)+(s>0)+(p>0)>=2)
				{
					if(r){
                        double p1 = (p*r)/(double)(r*s+s*p+p*r);
						dp[r-1][s][p]+=p1*dp[r][s][p];
					}
					if(s){
                        double p2 = (r*s)/(double)(r*s+s*p+p*r);
						dp[r][s-1][p]+=p2*dp[r][s][p];
					}
					if(p){
                        double p3= (s*p)/(double)(r*s+s*p+p*r);
                        dp[r][s][p-1]+=p3*dp[r][s][p];
					}

				}



    double ans = 0;
    for(int r=1;r<=rock;r++) ans+=dp[r][0][0];
	cout<<ans<<" ";
	ans=0;
	for(int s=1;s<=scissor;s++) ans+=dp[0][s][0];
	cout<<ans<<" ";
	ans=0;
	for(int p=1;p<=paper;p++) ans+=dp[0][0][p];
	cout<<ans<<endl<<endl;



}
