#include<iostream>
#define N 9
using namespace std;
int main()
{
	int n, A[9], B[9], C[9];
	int frontA = 0, rearA = 0;
	int frontB = 0, rearB = 0;
	int frontC = 0, rearC = 0;
	int TagA = 0, TagB = 0, TagC = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int selectFunction, QueueSelect, x;
		cin >> selectFunction >> QueueSelect;
		switch (selectFunction)
		{
		case 1:
			cin >> x;
			switch (QueueSelect)
			{
			case 1:
				if (frontA != rearA || TagA != 1)
				{
					A[rearA] = x;
					rearA = (rearA + 1) % N;
					if (rearA == frontA)
						TagA = 1;
				}
				break;
			case 2:
				if (frontB != rearB || TagB != 1)
				{
					B[rearB] = x;
					rearB = (rearB + 1) % N;
					if (rearB == frontB)
						TagB = 1;
				}
				break;
			case 3:
				if (frontC != rearC || TagC != 1)
				{
					C[rearC] = x;
					rearC = (rearC + 1) % N;
					if (rearC == frontC)
						TagC = 1;
				}
				break;
			}
			break;
		case 2:
			switch (QueueSelect)
			{
			case 1:
				if (frontA != rearA || TagA != 0)
				{
					frontA = (frontA + 1) % N;
					if (rearA == frontA)
						TagA = 0;
				}
				break;
			case 2:
				if (frontB != rearB || TagB != 0)
				{
					frontB = (frontB + 1) % N;
					if (rearB == frontB)
						TagB = 0;
				}
				break;
			case 3:
				if (frontC != rearC || TagC != 0)
				{
					frontC = (frontC + 1) % N;
					if (rearC == frontC)
						TagC = 0;
				}
				break;
			}
			break;
		case 3:
			cin >> x;
			switch (QueueSelect)
			{
			case 1:
				if (frontA != rearA || TagA != 1)
				{
					if (frontA == 0)
						frontA = 9;
					A[--frontA] = x;
				}
				break;
			case 2:
				if (frontB != rearB || TagB != 1)
				{
					if (frontB == 0)
						frontB = 9;
					B[--frontB] = x;
				}
				break;
			case 3:
				if (frontC != rearC || TagC != 1)
				{
					if (frontC == 0)
						frontC = 9;
					C[--frontC] = x;
				}
				break;
			}
			break;
		case 4:
			switch (QueueSelect)
			{
			case 1:
				if (frontA != rearA || TagA != 0)
				{
					if (rearA <= 0)
						rearA = 9;
					rearA--;
				}
				break;
			case 2:
				if (frontB != rearB || TagB != 0)
				{
					if (rearB <= 0)
						rearB = 9;
					rearB--;
				}
				break;
			case 3:
				if (frontC != rearC || TagC != 0)
				{
					if (rearC <= 0)
						rearC = 9;
					rearC--;
				}
				break;
			}
			break;
		case 5:
			switch (QueueSelect)
			{
			case 1:
				cout << "A:";
				for (int i = frontA; i != rearA; i = (i + 1) % N)
				{
					cout << A[i] << " ";
				}
				cout << endl;
				cout << "front:" << frontA << " rear:" << rearA << endl;
				break;
			case 2:
				cout << "B:";
				for (int i = frontB; i != rearB; i = (i + 1) % N)
				{
					cout << B[i] << " ";
				}
				cout << endl;
				cout << "front:" << frontB << " rear:" << rearB << endl;
				break;
			case 3:
				cout << "C:";
				for (int i = frontC; i != rearC; i = (i + 1) % N)
				{
					cout << C[i] << " ";
				}
				cout << endl;
				cout << "front:" << frontC << " rear:" << rearC << endl;
				break;
			}
			break;
		}
	}
}
/*
17
1 1 2
3 2 4
1 3 5
1 2 8
2 3
5 1
5 2
5 3
3 3 10
1 2 20
4 2
3 1 30
4 1
1 3 40
5 1 
5 2
5 3
*/
/*
A:2
front:0 rear:1
B:4,8
front:8 rear:1
C:
front:1 rear:1
*/
/*
A:30
front:8 rear:0
B:4,8
front:8 rear:1
C:10,40
front:0 rear:2
*/