#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

int di[4] = { -1,0,1,0};
int dj[4] = { 0,1,0,-1};

int gcd(int x, int y) {
	int z=0;

	while (y != 0) {
		//cout << x<<' '<<y<<'\n';
		z = x % y;
		x = y;
		y = z;
	}

	return x;
}


int main()
{
	int x, y;
	cin >> x >> y;

	int g = gcd(x, y);

	cout << g << '\n' << x * y / g;
}

