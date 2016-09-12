#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string ret;
        stack<TreeNode*> pStack;
        stack<int> sStack;
        pStack.push(root);
        sStack.push(0);
        char tmpS[100];
		while (!pStack.empty()){
			switch (sStack.top()){
				case 0:
					if (pStack.top()!=NULL){
						sprintf(tmpS,"%d",pStack.top()->val);
						ret.append(tmpS);
						ret.append(",");
						sStack.pop();
						sStack.push(1);
						pStack.push(pStack.top()->left);
						sStack.push(0);
					}
					else{
						ret.append("NULL,");	
						pStack.pop();
						sStack.pop();											
					}
					break;
				case 1:					
					sStack.pop();
					sStack.push(2);
					pStack.push(pStack.top()->right);
					sStack.push(0);
					break;
				case 2:
					pStack.pop();
					sStack.pop();
					break;						
			}
		}
		return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	TreeNode* ret;
        stack<TreeNode**> pStack;
        stack<int> sStack;
        pStack.push(&ret);
        sStack.push(0);
        while (data.length()!=0){
        	int end=data.find_first_of(',',0);
        	
        	//	printf("%d\n",sStack.top());
        		switch (sStack.top()){
					case 0:{
						if (data[0]=='N'){
			        		*pStack.top()=NULL;
			        		pStack.pop();
			        		sStack.pop();
			        		data.erase(0,end+1);
			        	//	printf("N\n");
			        		break;
			        	}else{
							stringstream ss;
							ss<<data.substr(0,end);
							int val;
							ss>>val;
							TreeNode* tmp=new TreeNode(val);
	        				sStack.pop();
	        				sStack.push(1);
	        				*pStack.top()=tmp;
	        				pStack.push(&(tmp->left));
	        				sStack.push(0);
	        				data.erase(0,end+1);
	        				break;
        				}
					}					
											
        			case 1:
        				sStack.pop();
        				sStack.push(2);        				
        				pStack.push(&((*pStack.top())->right));
        				sStack.push(0);
        				break;
        			case 2:
        				sStack.pop();
        				pStack.pop();
        				break;
				}
        		
        		
        	
        //	cout<<data<<endl;
        	
        }
        return ret;
    }
};

int main(){
	Codec *s=new Codec();
	TreeNode *a=new TreeNode(1);
	TreeNode *b=new TreeNode(2);
	TreeNode *c=new TreeNode(3);
	TreeNode *d=new TreeNode(4);
	TreeNode *e=new TreeNode(5); 
	a->left=b;
	a->right=c;
	c->left=d;
	c->right=e;
//	cout<<s->serialize(a);
    
   //cout<<s->serialize(s->deserialize("1,2,NULL,NULL,3,4,NULL,NULL,5,NULL,NULL,"));
   //s->deserialize("1,2,NULL,NULL,3,NULL,NULL,");
    cout<<s->serialize(s->deserialize("NULL,"));
}
