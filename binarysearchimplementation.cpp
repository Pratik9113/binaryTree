#include<iostream>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>

using namespace std;
class node{
   public : 
   int  data;
    node* left;
    node* right;

    node(int d){
        this ->data = d;
        this ->left = NULL;
        this->right = NULL;
    }
};
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}
void levelorderbyforloop(node* root){
     if (root == NULL) return;
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){

        int n = q.size();
        for(int i=0;i<n;i++){
             node* temp = q.front();
             q.pop();
             cout << temp->data << " ";
             if(temp->left){
                q.push(temp->left);
             }
             if (temp->right){
                q.push(temp->right);
             }
        }
        cout << endl;
    }
}
int  countleafnode(node* root){
    int a = 0;
    if(root ==NULL) {
        //cout << count << " ";
        return 0;
    }
     if (root->left ==NULL && root->right == NULL){
        return 1;
    }
    int left =  countleafnode(root->left);
    int right =  countleafnode(root->right);
    return left + right;
}
void levelreverseordertransversal(node* root){
    if (root==NULL) return;
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    s.push(root);
    while(!q.empty()){
            node* temp = q.front();
           // s.push(temp);
            q.pop();

                if(temp->left){
                    q.push(temp->left);
                    s.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                    s.push(temp->right);
                 
               }
            }
         while(!s.empty()){
           
           node* curr = s.top();
            
           cout << curr->data  << " ";
            s.pop();
         }
    }

void levelordertransveral(node* root){
    if (root == NULL) return;
        queue<node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();

           
            if(temp ==NULL){
                  cout << endl;
                  if(!q.empty()){
                    q.push(NULL);
                  }
            }else{
                cout <<  temp->data << " ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){     
                     q.push(temp->right);
                }
            }
        }
}
void reverseleveltransversal(node* root){
   if (root == NULL) return;
   if(root){
       reverseleveltransversal(root->right);
       reverseleveltransversal(root->left);
       cout << root->data  << " ";
   }
}

node* buildTree(node* root){
    int data;
    cout << "enter the data : ";
    cin >> data;
    root = new node(data);
    if (data ==  -1){
        return NULL;
    }
    cout << "enter the left root data - > " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the right  root data - > " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
int maximumheight(node* root){
    if(root==NULL){
        return 0;
    }
    int h1 = maximumheight(root->left);
    int h2 = maximumheight(root->right);
    int ans =  max(h1,h2)+1;
    return ans;
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = maximumheight(root->left) + maximumheight(root->right) +1;
    int ans = max(opt1 , max(opt2, opt3));
    return ans;
}

pair<int,int> fastdiameter(node* root){
    if(root == NULL){
        pair<int, int>p = make_pair(0,0);
        return p;
    }
    pair<int, int>left = fastdiameter(root->left);
    pair<int, int>right = fastdiameter(root->right);
    
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second +1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2,opt3));
    ans.second = max(left.second, right.second) +1;
    return ans;
}
int fdiameter(node* root){
    return (fastdiameter(root).first);
}
 vector<int> levelorder(node* root, vector<int>&ans, int maxo){
        if(root== NULL){
        return ans;
        }

        queue<node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            maxo = max(maxo,temp->data);
                if(q.front() ==NULL){
                    ans.push_back(maxo);
                    q.pop();
                    }
                    if (temp ==NULL){
                        if(!q.empty()){
                            q.push(NULL);
                        }
                    }
                    else{
                    if(root->left){
                        q.push(root->left);
                    }
                    if(root->right){
                        q.push(root->right);
                    }
                }
            
        }
 return ans;
    }
bool isbalanced(node* root){
    if(root == NULL){
        return true;
    }
    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);
    bool diff = abs(maximumheight(root->left) - maximumheight(root->right)) <=1;
    if(left && right && diff){
        return true;
    }return false;
}
int main(){
   node* root =  NULL;
   root = buildTree(root);
  /* //levelordertransveral(root);
   //levelorderbyforloop(root);
   //reverseleveltransversal(root);
   levelreverseordertransversal(root);
   cout << endl;
   cout << "inorder" << endl;
   inorder(root);
   cout << "preorder" << endl;
   preorder(root);
   cout << "postorder" << endl;
   postorder(root);
   cout <<  endl;
   //int a =0;
  //cout <<  countleafnode(root);
  // cout << "count leaf node  :  " << a;
  cout << maximumheight(root);
  cout << endl << "diameter of the binary treee :  ";
  cout << diameter(root);
  cout << endl << "fastest way to find diameter  : " << fdiameter(root);
  cout << endl << "the tree is balnced or not : " << isbalanced(root);*/
  int maxo =-1;
  vector<int>ans;
  levelorder(root, ans,maxo);
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
}