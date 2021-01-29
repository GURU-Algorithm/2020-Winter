#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> inorder(100000);
vector<int> postorder(100000);
void preorder(int in_st, int in_en, int po_st, int po_en) {
	// 종료 조건 (index 범위를 벗어났을 때)
	if (in_st < 0 || po_st < 0 || in_en >= n || po_en >= n) return;
	if (in_st > in_en || po_st > po_en) return;

	printf("%d ", postorder[po_en]);
	int index = -1;
	for (int i = in_st; i <= in_en; i++) {
		if (inorder[i] == postorder[po_en])
			index = i;
	}
	
	// 종료 조건 (찾고자 하는 원소가 없는 경우)
	if(index == -1) return;
	// 왼쪽 subtree
	preorder(in_st, index - 1, po_st, po_st + (index - in_st) - 1);
	// 오른쪽 subtree
	preorder(index + 1, in_en, po_st + (index - in_st), po_en - 1);
}


int main() {
	int i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) scanf_s("%d", &inorder[i]);
	for (i = 0; i < n; i++) scanf_s("%d", &postorder[i]);
	preorder(0, n-1, 0, n-1);
	return 0;
}
