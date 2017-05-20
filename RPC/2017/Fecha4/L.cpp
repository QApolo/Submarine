#include <bits/stdc++.h>

using namespace std;

const int S = 31623;

bool crib[S];
int primo[S];
int cp;

void init()
{
	cp = 0;
	crib[0] = true;
	crib[1] = true;

	for(int i = 2; i < S; i++)
	{
		if(!crib[i])
		{
			for(int j = i; j < S; j += i )
			{
				crib[j] = 1;
			}
			primo[cp++] = i; 
		}
	}
}

vector <int> factor(int n)
{
	vector <int> f;
	for(int i = 0; i < cp && n > 1; i++)
	{
		if(n%primo[i] == 0) f.push_back(primo[i]);

		while(n%primo[i] == 0)
		{
			n /= primo[i];
		}
	}
	return f;
}

typedef long long ll;

ll EulerPhi(ll N) {
	ll PF_idx = 0, PF = primo[PF_idx], ans = N; // start from ans = N

	while (PF * PF <= N) 
	{
		if (N % PF == 0) ans -= ans / PF; // only count unique factor

		while (N % PF == 0) N /= PF;
		PF = primo[++PF_idx];
	}
	if (N != 1) ans -= ans / N; // last factor
return ans;
}

int main()
{
	init();
	vector <int> f;

	double fn, fp;
	int t, n, ci;

	cin >> t;

	while(t--)
	{
		scanf("%d", &n);
		ll res = EulerPhi(n);
		printf("%lld %.4f\n",res, (double)((double)res)/2 );
	}

return 0;
}