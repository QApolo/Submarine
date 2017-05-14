#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
int main()
{
	ull n,res;
	while(cin >> n && n != 0)
	{
		if(n == 1) cout << 1 <<'\n';
		else
		{
			 res = 2LL<<(ull)(log2(n))-1;
			 res = n-res;	
		cout << (1+2*res) <<'\n';
		}
		
	}
return 0;
}