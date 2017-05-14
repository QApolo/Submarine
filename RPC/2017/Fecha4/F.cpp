#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)
	{
		int F;
		int m = 1;
		string s;
		cin >> s >> F;
		
		int length = s.length();
		vector<int> f(length, 1);

		for(int i = length - 1; i >= 0; --i)
		{
			for(int j = i + 1; j < length; ++j)
			{
				if((s[i] + F - 'a') % 26 <= s[j] -'a')
					f[i] = max(f[i], 1 + f[j]);
			}
			m = max(m, f[i]);
		}
		cout << m << '\n';
	}
	return 0;
}