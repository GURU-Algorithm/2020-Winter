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

	// postorder�� ���� ������ root
	// �� root�� inorder������ ��� ��ġ�� �ִ��� Ȯ���ؾ� �ϹǷ�
	// inorder_index�� ����� ���´�.
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
		// 1. root�� ã�´�.
		int root = postorder[postorder_end];
		cout << root << " ";

		// 2. inorder������ root index�� ã�´�.
		int inorder_root_index = inorder_index[root];

		// 3. �� root index�� �������� ������ ���� �ڽĳ���̹Ƿ�
		//	  ���� �ڽ� ����� ����� ���Ѵ�.
		int left_size = inorder_root_index - inorder_start;

		// 4. �ڽĳ��� ���� �ٽ� root node�� ���ϴ� ��͸� �Ѵ�.
		// 4-1. ���� �ڽĳ��
		findPreorder(inorder_start, inorder_root_index - 1, postorder_start, postorder_start + left_size - 1);
		// 4-2. ������ �ڽĳ��
		findPreorder(inorder_root_index + 1, inorder_end, postorder_start+left_size, postorder_end - 1);
	}


}