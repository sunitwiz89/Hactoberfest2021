#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD
#pragma once

#pragma GCC target("sse4")
#pragma inline_recursion( [ { on } ] )
#include<bits/stdc++.h>
using namespace std;                                                                                                                                          
typedef  int ll;                             //g++ ll.cpp -o ll.exe  




vector<ll> v;
ll sum1=0,m,n,k,d,a;

 inline void solve(ll i,ll sum, ll x,ll dd)
 {
  

  if(i>n)
  {
    if(x==k)
      sum1=max(sum1,sum);
    return;
  }

  if(i>n-(k-x)+1)
  {
    
    return;
  }


#pragma omp parallel
  {
    #pragma omp single
    {
  #pragma omp task shared()
      {


  if(dd>=1)
  {
    solve(i+1,sum+m*(v[i]-v[i-1]),x,dd-1);
  }
  else
  {
    solve(i+1,sum+(v[i]-v[i-1]),x,dd-1);
  }
  }


 if(x>=k)
  {
    sum1=max(sum1,sum);
    return;
  }
  #pragma omp task shared()
  {


  solve(i+1,sum,x+1,d);
}
}
}

return;

}
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
   
   
   scanf("%d %d %d %d", &n, &k, &d, &m);

   v.resize(n+1);
   v[0]=0;

   for(ll i=1;i<=n;i++)
   {
    
    scanf("%d",&a);
    v[i]=a+v[i-1];
   }

   for(ll i=1;i<=(n-k)+1;i++)
   {
    solve(i+1,v[i-1],1,d);
   }

   cout<<sum1<<endl;

   

  




 
 
 
 
    
    return 0;
}
