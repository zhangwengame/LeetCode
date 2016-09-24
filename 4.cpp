//log(min(m,n))
class Solution {
public:
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
	if (A.size()>B.size())
	    return findMedianSortedArrays(B,A);
	if (A.size()==0) 
	    return B.size()%2==1?B[B.size()/2]:(B[B.size()/2]+B[B.size()/2-1])*0.5;
    int l=0; 
    int r=A.size();
    int n=A.size();
    int m=B.size();
    int odd=(m+n)%2==1?1:0;
    while (l<=r) {
        int i=(l+r)>>1;
        int j=((m+n+1)>>1)-i;
        if (i<n && j>0 && A[i]< B[j-1])
            l=i+1;
        else if (j<m && i>0 && B[j]<A[i-1])
            r=i-1;
        else {
            int max_of_left;
            if (i==0)
                max_of_left=B[j-1];
            else if (j==0)
                max_of_left=A[i-1];
            else 
                max_of_left=max(A[i-1],B[j-1]);
            
            if (odd)
                return max_of_left;
            int min_of_right;
            if (i==n)
                min_of_right=B[j];
            else if (j==m)
                min_of_right=A[i];
            else
                min_of_right=min(A[i],B[j]);
            return (min_of_right+max_of_left)*0.5;
        }
    }
    return -1;
}


};
//log(m+n)
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
			return find_kth(A,sa + ia, m - ia, B,sb, n-(n-ib), k - ia);
		else if (A[sa+ia - 1] > B[sb+ib - 1])
			return find_kth(A, sa, m-(m-ia), B ,sb+ ib, n - ib, k - ib);
		else
			return A[sa+ia - 1];
	}
};

