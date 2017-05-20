#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	while(cin >> t)
	{
		while(t--)
		{
			int n,m;
			pair<int,int> aux;
			vector <pair<int,int> > v;
			cin >> n >> m;
			for (int i = 0; i < m; ++i)
			{
				cin >> aux.first >> aux.second;
				v.push_back(aux);
			}
			sort(v.begin(), v.end());
			set <int> s;
			int ct = 0;
			for (int i = 0; i < m; ++i) 
			{
				while(!s.empty() && *s.begin() <= v[i].first)
					s.erase(s.begin());
				
				set<int> :: iterator it;
				for (it = s.begin(); it != s.end(); ++it)
				{
					if(*it < v[i].second)
						ct++;
				}
				s.insert(v[i].second);
			}
			cout << ct << '\n';
		}
	}
	return 0;
}