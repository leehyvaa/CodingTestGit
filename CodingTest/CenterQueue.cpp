#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxQ;
priority_queue<int> minQ;

void Push(int num);
void Pop();
void Resetting();
int GetCount();


int main()
{
	int n;
	cin >> n;
	
	for (size_t i = 0; i < n; i++)
	{
		int num;
		string str;
		cin >> str;

		if (str == "PUSH")
		{
			cin >> num;
			Push(num);
		}
		else if (str == "POP")
			Pop();
		else if (str == "SIZE")
			cout << "		" << GetCount() << "\n";
	}
}

void Push(int num)
{
	//�ݵ�� maxQ���� Ǫ��
	maxQ.push(num);
	Resetting();
	
	//����� ���
	cout << "		" << maxQ.top() << "\n";
}

void Pop()
{
	maxQ.pop();
	Resetting();

	if (maxQ.size() == 0)
		cout << "		NO ITEM\n";
	else
		cout << "		" << maxQ.top() << "\n";
}

void Resetting()
{
	//minQ�� push�Ҷ��� top�� ���� �ݵ�� -�ٿ�����

	//������ ���̰� 1���� Ŭ ���
	while(maxQ.size() - minQ.size() > 1 || maxQ.size() < minQ.size())
	{
		if (maxQ.size() > minQ.size())
		{
			minQ.push(-maxQ.top());
			maxQ.pop();
		}
		else
		{
			maxQ.push(-minQ.top());
			minQ.pop();
		}
	}

	if (maxQ.size() < 1 || minQ.size() < 1)
		return;

	//maxQ�� top�� minQ�� top���� ���� �������
	while (maxQ.top() > -minQ.top())
	{
		minQ.push(-maxQ.top());
		maxQ.pop();
		maxQ.push(-minQ.top());
		minQ.pop();
	}

	//cout << "maxTop : " << maxQ.top() << "minTop : " << -minQ.top() <<"\n";
}

int GetCount()
{
	return (minQ.size() + maxQ.size());
}

