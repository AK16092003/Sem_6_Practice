#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll rand(ll l, ll r){
   static mt19937 
   rng(chrono::steady_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> ludo(l, r); 
   return ludo(rng);
}


ll power(ll a , ll b , ll mod)
{
	ll ans = 1;
	if(b==0) return 1;
	if(b%2 == 0)
	{
		ans *= power(a , b/2 , mod);	
		ans %= mod;
		ans *= ans;
		ans %= mod;
	}
	else
	{
		ans *= a;
		ans %= mod;
		ans *= power(a , b-1 , mod);
		ans %= mod;
	}
	return ans;
}

int main()
{	
	ll pr;
	cout << "Enter prime number: ";
	cin >> pr;
	
	if(pr == 2)
	{
		cout << "Prime" << endl;
		return 0;
	}
	if(pr%2 == 0)
	{
		cout << "Composite" << endl;
		return 0;
	}
		
	for(int i = 0 ; i < 100 ; i ++)
	{
		ll a = rand(2 , pr-1);
		ll ans = power(a , pr - 1 , pr);
		if(ans != 1)
		{
			cout << "Composite " << endl;	
			return 0;
		}	
	}
	
	cout << "May Be Prime Number" << endl;
	return 0;
}