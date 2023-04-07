#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int getMin(int a,int b,int c)
{
	int m = min(a, b);
	m = min(m, c);
	return m;
}

void Distance(vector<vector<int>> d,int a,int b,int k,string A,string B)
{
	for (int m = 0; m <= a;m++)
		d[0][m] = m * k;
	for (int n = 0; n <= b; n++)
		d[n][0] = n * k;
	for(int i=1;i<=a;i++)
		for (int j = 1; j <= b; j++)
			d[i][j] = getMin(d[i][j - 1] + k, d[i - 1][j] + k, d[i - 1][j - 1] + abs(A[i-1] - B[j-1]));
}

int main()
{
	ifstream infile;
	infile.open("input.txt");
	string A, B;
	getline(infile, A);
	getline(infile, B);
	int a = (int)A.size(),b = (int)B.size();
	int k;
	infile >> k;
	vector<vector<int>> d(a + 1, vector<int>(b + 1, 1e9));
	Distance(d, a, b, k, A, B);
	fstream outfile;
	outfile.open("output.txt");
	outfile << d[a][b];
	infile.close();
	outfile.close();
	return 0;
}