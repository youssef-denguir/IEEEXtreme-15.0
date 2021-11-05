#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define repinv(i,n) for(ll i=n-1;i>-1;i--)
#define MOD 1000000007
#define endl '\n'
typedef long long ll;
vector< vector< vector< vector< ll> > > > dp;
int v[1001][1001];
int m,x,y,k;
ll solve(int i,int j,int succ,int nb){

    ll &ret=dp[i][j][nb][succ];

    if(ret!=-1)
        return ret;
    if(j==x-1){
        if(i<m-1){
            if(nb==y-1&&(succ+1<=k))
                ret=v[i][j]+solve(i+1,0,succ+1,0);
            else if(nb==y&&(succ<=k))
                ret=solve(i+1,0,0,0);
            else{
                ret=-1e18;
            }
        }
        else{
            if(nb==y-1&&(succ+1<=k))
                ret=v[i][j];
            else if(nb==y&&(succ<=k))
                ret=0;
            else{
                ret=-1e18;
            }
        }
    }
    else{
        if((succ+1<=k)&&nb<y){
            ret=max(v[i][j]+solve(i,j+1,succ+1,nb+1),solve(i,j+1,0,nb));
        }
        else

            ret=solve(i,j+1,0,nb);

    }

    return ret;




}




int main(){
    int tc;
    cin>>tc;

    while(tc--){

        cin>>m>>x>>y>>k;
        rep(i,m){

            rep(j,x){
                cin>>v[i][j];
            }
        }
        dp.clear();
        dp.resize(m+1);
        for(int i=0;i<=m;i++){
            dp[i].resize(x+1);
            for(int j=0;j<=x;j++){
                dp[i][j].resize(y+1);
                for(int l=0;l<=y;l++)
                    dp[i][j][l].resize(k+1,-1);

            }


        }
        ll ans=solve(0,0,0,0);
        if(ans<0)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans<<endl;




    }

}

