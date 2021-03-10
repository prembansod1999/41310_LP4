#include<bits/stdc++.h>
using namespace std;
map<string,float> input(map<string,float> m,int n)
{
	string s;
	float x;
	for(int i = 0;i<n;i++)
	{
		cin>>s;
		cin>>x;
		m[s] = x;		
	}
	return m;
}
void print(map<string,float> m,int n)
{
	for(auto i:m)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
}
void unionOfFuzzySets(map<string,float> m1,map<string,float> m2,int n)
{
	map<string,float> m;	
	for(auto it1 = m1.begin(),it2 = m2.begin();it1 != m1.end();it1++,it2++)
	{
		m[it1->first] = max(it1->second,it2->second);
	}
	print(m,n);
}
void intersectionOfFuzzySets(map<string,float> m1,map<string,float> m2,int n)
{
	map<string,float> m;	
	for(auto it1 = m1.begin(),it2 = m2.begin();it1 != m1.end();it1++,it2++)
	{
		m[it1->first] = min(it1->second,it2->second);
	}
	print(m,n);
}
void complementOfFuzzySets(map<string,float> m1,int n)
{
	map<string,float> m;	
	for(auto it1 = m1.begin();it1 != m1.end();it1++)
	{
		m[it1->first] = 1 - it1->second;
	}
	print(m,n);
}
void differenceOfFuzzySets(map<string,float> m1,map<string,float> m2,int n)
{
	map<string,float> m;	
	for(auto it1 = m1.begin(),it2 = m2.begin();it1 != m1.end();it1++,it2++)
	{
		m[it1->first] = min(it1->second,1 - it2->second);
	}
	print(m,n);
}
void cartesionProduct()
{
	map<string,float> m1,m2;
	int n;
	cout<<"Enter size of first Fuzzy set\n";
	cin>>n;
	m1 = input(m1,n);
	cout<<"Enter size of second Fuzzy set\n";
	cin>>n;
	m2 = input(m2,n);	
	cout<<"Pair      associated membership"<<endl;
	for(auto it1 = m1.begin();it1 != m1.end();it1++)
	{
		for(auto it2 = m2.begin();it2 != m2.end();it2++)
		{
			cout<<it1->first<<", "<<it2->first<<"      ";
			cout<<min(it1->second,it2->second)<<endl;
		}		
	}
}
void minMaxComposition()
{
	int r1,c1,r2,c2;
	cout<<"Enter rows for first relation"<<endl;
	cin>>r1;
	cout<<"Enter columns for first relation"<<endl;
	cin>>c1;
	float arr1[r1][c1];
	cout<<"Enter first matrix\n";
	for(int i = 0;i<r1;i++)
	{
		for(int j = 0;j<c1;j++)
		{
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter rows for second relation"<<endl;
	cin>>r2;
	cout<<"Enter columns for second relation"<<endl;
	cin>>c2;
	float arr2[r2][c2], res[r1][c2];
	cout<<"Enter second matrix\n";
	for(int i = 0;i<r2;i++)
	{
		for(int j = 0;j<c2;j++)
		{
			cin>>arr2[i][j];
		}
	}
	for(int i=0; i<r1; ++i)
	{
		for(int j=0; j<c2; ++j)
		{
			res[i][j] = 0.0;
			for(int k=0; k<c1; ++k) 
			{
   				res[i][j] = max(res[i][j],min(arr1[i][k],arr2[k][j]));
			}
		}
	}	
	cout<<"\nOutput\n";
	for(int i = 0;i<r1;i++)
	{
		for(int j = 0;j<c2;j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
}
int main()
{
	map<string,float> m1;
	map<string,float> m2;
	int x,n;
	cout<<"Enter size of Fuzzy set\n";
	cin>>n;
	cout<<"Enter first fuzzy set\n";
	m1 = input(m1,n);
	cout<<"Enter second fuzzy set\n";
	m2 = input(m2,n);
	cout<<"\nSet 1\n";
	print(m1,n);
	cout<<"Set 2\n";
	print(m2,n);
	do
	{	
		cout<<"1.Union\n2.Intersection\n3.Complement\n4.Difference\n5.Cartesion Product\n6.Min_Max Composition\n7.Exit\n";
		cin>>x;
		switch(x)
		{
			case 1: unionOfFuzzySets(m1,m2,n);
				break;
			case 2: intersectionOfFuzzySets(m1,m2,n);
				break;
			case 3: cout<<"\nComplement of set 1\n";
				complementOfFuzzySets(m1,n);
				cout<<"Complement of set 2\n";
				complementOfFuzzySets(m2,n);
				break;
			case 4: differenceOfFuzzySets(m1,m2,n);
				break;
			case 5: cartesionProduct();
				break;
			case 6: minMaxComposition();
				break;
			case 7: return 0;		
		}
	}while(true);
	return 0;
}
