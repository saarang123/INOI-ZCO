#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

const int N=3005;
vii graph(N);
int dp[N];

void dfs(int v)
{
    if(dp[v]!=-1) return;
    dp[v] = 1;
    for(int u: graph[v])
    {
        dfs(u);
        dp[v] = max(dp[v], 1+dp[u]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,l,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> l;
        int a[n+5];
        RE(i,n) cin >> a[i];

        //Binary searching for answer which is between 0-n
        int m1=0, m2=n,x;
        while(m1<m2)
        {
            int gr[n+4][n+4];
            x = (m1+m2+1)/2;
            for(i=1;i<=n;i++)
            {
                graph[i].clear();
                dp[i] = -1;
            }
            //Making graphs
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(abs(i-j)<x) continue;
                    gr[i][j] = 0;
                    if(a[j]<=a[i])
                    {
                        graph[i].pb(j);
                        gr[i][j] = 1;
                    }
                }
            }

            /*
            RE(i,n)
            {
                for(int j: graph[i])
                {
                    cout << j << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            */

            //Checking for cycles
            bool pos=0;
            for(i=1; i<=n; i++)
            {
                for(int v: graph[i])
                {
                    if(gr[v][i])
                    {
                        pos = true;
                        break;
                    }
                }
            }

            //Using DFS to check for sequence >=L in length
            if(!pos)
            {
                for(i=1; i<=n; i++)
                {
                    dfs(i);
                    if(dp[i]>=l)
                    {
                        pos = true;
                    }
                }
            }

            //RE(i,n) cout << dp[i] << " ";
            //cout << "\n";
            //cout << m1 << " " << x << " " << m2 << "\n";

            if(pos)
            {
                m1 = x;
            }
            else
            {
                m2 = x-1;
            }

        }
        cout << m1 << "\n";  //Answer

    }
    return 0;
}
