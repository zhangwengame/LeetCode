
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
	int total = A.size() + B.size();
	if (total & 0x1)
		return find_kth(A, 0, A.size(), B, 0,B.size(), total / 2 + 1);
	else
	return (find_kth(A, 0, A.size(), B, 0, B.size(), total / 2)
	+ find_kth(A, 0, A.size(), B, 0, B.size(), total / 2 + 1)) / 2.0;
}
private:
	int find_kth(vector<int>& A, int sa, int m, vector<int>& B, int sb, int n, int k) {
		//always assume that m is equal or smaller than n
		if (m > n) return find_kth(B, sb, n, A, sa, m, k);
		if (m == 0) return B[sb+k - 1];
		if (k == 1) return min(A[sa+0], B[sb+0]);
		//divide k into two parts
		int ia = min(k / 2, m), ib = k - ia;
		if (A[sa+ia - 1] < B[sb+ib - 1])
			return find_kth(A,sa + ia, m - ia, B,sb, n, k - ia);
		else if (A[sa+ia - 1] > B[sb+ib - 1])
			return find_kth(A, sa, m, B ,sb+ ib, n - ib, k - ib);
		else
			return A[sa+ia - 1];
	}
};
int main(){

	Solution *s=new Solution();
	int l1[]={1,3,5};
	int l2[]={2,4,6,8};
	vector<int> v1(l1,l1+3);
	vector<int> v2(l2,l2+4);
	double ret=s->findMedianSortedArrays(v1,v2);
	printf("%lf\n",ret);

}


