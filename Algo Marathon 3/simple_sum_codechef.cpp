#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=1e7+5;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    vector<int>primes,totient(N),func(N);
    vector<bool>vis(N);
    totient[1]=1;
    func[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            primes.push_back(i);
            totient[i]=i-1;
            func[i]=i*(i-1)+totient[1];
        }
        for(int prime:primes){
            if(i*prime>=N) 
                break;
            vis[i*prime]=true;
            if(i%prime==0){
                totient[i*prime]=totient[i]*prime;
                func[i*prime]=(func[i]-func[i/prime])*(prime*prime+1)+func[i/prime];
                break;
            }
            totient[i*prime]=totient[i]*totient[prime];
            func[i*prime]=func[i]*func[prime];
        }
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<func[n]<<'\n';
   
    }
  return 0;
}
