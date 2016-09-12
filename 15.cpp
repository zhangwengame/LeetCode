//#include??cstdio>
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
vector<vector<int> > threeSum(vector<int>& num) {
	vector<vector<int> > result;
	if (num.size() < 3) return result;
	sort(num.begin(), num.end());
	const int target = 0;
	vector<int>::iterator last = num.end();
	for (vector<int>::iterator i = num.begin(); i < last-2; ++i) {
		vector<int>::iterator j = i+1;
		if (i > num.begin() && *i == *(i-1)) continue;
		vector<int>::iterator k = last-1;
		while (j < k) {
			if (*i + *j + *k < target) {
				++j;
				while(*j == *(j - 1) && j < k) ++j;
			} else if (*i + *j + *k > target) {
				--k;
				while(*k == *(k + 1) && j < k) --k;
			} else {
				vector<int> t;
				t.resize(3);
				t[0]=*i; t[1]=*j; t[2]=*k;
				result.push_back(t);
				++j;
				--k;
				while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
			}
		}
	}
	return result;
}
};
int main(){
	int a[]={-1,0,0,0,0,0,0};
	vector<int> t(a,a+7);
	Solution *s=new Solution();
	vector<vector<int> >  ret=s->threeSum(t);
	for (int i=0;i<ret.size();i++)
	{
		for (int j=0;j<ret[i].size();j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}


}

