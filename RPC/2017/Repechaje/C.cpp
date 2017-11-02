#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll prec[101][101];
ll C(ll, ll);

void init()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			prec[i][j] = 0;
		}
	}

	for(int i = 0; i <= 100; i++)
	{
		for(int j = 0; j < i; j++)
		{
 			prec[i][j] = C(i,j);
		}
	}

}

ll C(ll n, ll k)
{
	if(n < 0) return -1;
	if(n > 0 && k == 0) return 1;
	if(n == k) return 1;

	ll np = 0, kp = 0;
	if(prec[n-1][k-1] != 0) np = prec[n-1][k-1];
	if(prec[n-1][k] != 0) kp = prec[n-1][k];

	if(np != 0 && kp != 0)
	{
		prec[n-1][k-1] = np;
		prec[n-1][k] = kp;
		return np + kp;
	}
	if(np == 0 && kp != 0) 
	{
		prec[n-1][k] = kp;
		return C(n-1,k-1) + kp;
	}
	if(np != 0 && kp == 0) 
	{
		prec[n-1][k-1] = np;
		return np + C(n-1,k);
	}
	return C(n-1,k-1)+C(n-1,k);
}
int main()
{

	ll t,n;

	cin >> t;

	ll a,b;
	init();
	
	while(t--)
	{
		cin >> n;

		ll coef;
		a = n;
		b = 0;

		if(n == 0) cout << "1" << endl;
		else
		{
			for(ll i = 0; i <= n; i++)
			{
				coef = prec[n][i];
				if(coef > 1)
					cout << coef;
				if(a >= 1)
				{
					if(a > 1)
						cout << "x^" << a;
					else cout << "x";

				}
				if(b >= 1)
				{
					if(b > 1)		
						cout <<"y^" << b;
					else cout << "y";
				}
				a--;
				b++;
				if(i != n)	
					cout << "+";
			}
			cout << endl;

		}
		
	}

	return 0;
}