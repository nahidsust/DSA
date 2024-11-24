#include <bits/stdc++.h>
#define X 100000
using namespace std;
//That's MO's
int a[X], sum = 0,n,ans[X];
struct Query  {
    int  L, R,index;
};
bool compar(const Query& a,const Query&b){
    int v1=a.L/sqrt(n);
    int v2=b.L/sqrt(n);
    if(v1==v2)return a.R<b.R;
    return v1<v2;
}                            
void add(int ind){sum+=a[ind];}
void Remove(int ind){sum-=a[ind];}
int main() {
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
int q;
cin>>q;
struct Query query[q];
for(int i=0;i<q;i++){
       cin>>query[i].L>>query[i].R;
       query[i].index=i;
}                
sort(query,query+q,compar);
int L=0,R=-1;
for(int i=0;i<q;i++){
    while (R<query[i].R)add(++R);
     while (L<query[i].L)Remove(L++);
      while (R>query[i].R)Remove(R--);
       while (L>query[i].L)add(--L);
    ans[query[i].index]=sum;
}
for(int i=0;i<q;i++)cout<<ans[i]<<" ";
    return 0;
}


