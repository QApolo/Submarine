 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
 	int n, b;

 	int s,  r;
 	while(cin >> n >> b && !(b == 0 || n == 0))
 	{
 		s = 0;
 		for(int i = 0; i  < n; i++)
 		{
 			cin >> r;
 			s += r;
 		}
 		cout << b/ s <<endl;
 	}
 
 return 0;
 }