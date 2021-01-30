#include <iostream>
using namespace std;

int inorder[100001];
int postorder[100001];
int inorder_index[100001];
int nodeNum;

void findPreorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end);

int main()
{
	cin >> nodeNum;

	for (int i = 0; i < nodeNum; i++)
	{
		cin >> inorder[i];
	}

	for (int i = 0; i < nodeNum; i++)
	{
		cin >> postorder[i];
	}

	// postorder의 끝은 무조건 root
	// 그 root이 inorder에서는 어느 위치에 있는지 확인해야 하므로
	// inorder_index를 만들어 놓는다.
	for (int i = 0; i < nodeNum; i++) 
	{
		inorder_index[inorder[i]] = i;
	}


	findPreorder(0, nodeNum - 1, 0, nodeNum - 1);

	return 0;
}

void findPreorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end)
{
	if (inorder_start > inorder_end || postorder_start > postorder_end)
		return;

	else
	{
		// 1. root를 찾는다.
		int root = postorder[postorder_end];
		cout << root << " ";

		// 2. inorder에서의 root index를 찾는다.
		int inorder_root_index = inorder_index[root];

		// 3. 그 root index를 기준으로 왼쪽은 왼쪽 자식노드이므로
		//	  왼쪽 자식 노드의 사이즈를 구한다.
		int left_size = inorder_root_index - inorder_start;

		// 4. 자식노드들 끼리 다시 root node를 구하는 재귀를 한다.
		// 4-1. 왼쪽 자식노드
		findPreorder(inorder_start, inorder_root_index - 1, postorder_start, postorder_start + left_size - 1);
		// 4-2. 오른쪽 자식노드
		findPreorder(inorder_root_index + 1, inorder_end, postorder_start+left_size, postorder_end - 1);
	}


}