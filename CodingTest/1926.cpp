#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dis[502][502];

int n = 4, m = 6;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue <pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0, 0 });

	dis[0][0] = 1;

	for (int i = 0; i < n * m; i++)
	{
		//
	}


	while (!Q.empty())
	{
		int x = Q.front().X;
		int y = Q.front().Y;
		Q.pop();

		for (int i = 0; i<4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];

			if(vis[newX][newY] == 1)
				continue;
			if (board[newX][newY] == 1)
				continue;
			if(newX >= n || newY >= m || newX < 0 || newY < 0)
				continue;

			vis[newX][newY] = 1;
			Q.push({ newX,newY });
			dis[newX][newY] = dis[x][y] + 1;

		}
	}
	
	std::cout << dis[n][m];
}