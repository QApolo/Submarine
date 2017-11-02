#include <bits/stdc++.h>

using namespace std;

string transform(string n)
{
	int suma = 0;
	string r = "";
	for(int i = 0; i < n.length(); i++)
	{
		suma += n[i]-'0';
	}
	
	while(suma)
	{
		r.push_back(suma%10+'0');
		suma /= 10;
	}
	reverse(r.begin(),r.end());
	return r;
}



int main()
{
	
	string num;
	

	while(cin >> num)
	{
		if(num[0] == '0') break;
		while(num.length() > 1)
		{
			num = transform(num);
		}
		cout << num << endl;
	}
	
	
	
	
	return 0;
}
