#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> FibonacciMultiply(vector<int> X, vector<int> Y)
{
	int m = X.size();
	int n = Y.size();
	vector<int> Z(m + n, 0);
	int hold = 0;
	for (int k = 0; k < n + m - 1; k++)
	{
		for (int i = 0; i < m; i++)
		{
			int j = k - i;
			if (j >= 0 && j < n && i + j == k)
			{
				hold += X[i] *Y[j];
			}
		}

		Z[k] = hold % 10;
		hold /= 10;
	}

	Z[m + n - 1] = hold;
	while (Z.size() > 1 && Z.back() == 0)
	{
		Z.pop_back();
	}

	reverse(Z.begin(), Z.end());
	return Z;
}

int main()
{
	vector<int> X = { 1, 2, 3 };
	// example X
	vector<int> Y = { 4, 5 };
	// example Y
	vector<int> Z = FibonacciMultiply(X, Y);
	cout << "The product of two input vector is : ";
	for (int i = 0; i < Z.size(); i++)
	{
		cout << Z[i];
	}

	cout << endl;
	return 0;
}