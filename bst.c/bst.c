#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof (struct node));
    newnode->data = data;
    newnode->left =NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* createbst(struct node* root, int data ){
    if (root ==NULL){
        root = createnode(data);
    }else{
        if(root->data > data){
            root ->left = createbst(root->left,data);
        }else if (root->data <data){
            root->right  = createbst(root->right,data);
        }
    }
    return root;
}
void inorder(struct node* root ){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node* root ){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root ){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);

}
struct node* minval(struct node* root){
    struct node* temp = root;
    while(temp->right !=NULL){
        temp = temp->right;
    }
    return temp;
}
struct node* deletefrombst(struct node* root, int val){
    // base case
    if(root ==NULL){
        return root;
    }
    if(root->data ==val){
        if(root->left ==NULL && root->right ==NULL){
            free(root);
            return NULL;
        }

        if(root->left !=NULL && root->right ==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        if(root->right !=NULL && root->left ==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        
        if(root->left !=NULL && root->right !=NULL){
            int mini =  minval(root->right)->data;
            root->data = mini;
            root->right = deletefrombst(root->right,mini);
            return root;
        }

    }else if(root->data > val){
            root ->left = deletefrombst(root->left,val);
            return root;
    }else if (root->data <val){
            root->right  = deletefrombst(root->right,val);
            return root;
    }
}
void search(struct node* root, int key){
    struct node* temp = root;
    if(temp==NULL){
        printf("notfound");
    }else{
        while(temp!=NULL){
            if(temp->data == key){
                printf("found");
                break;
            }else if (temp->data >key){
                temp =temp->left;
            }else if(temp->data <key){
                temp = temp->right;
            }
        }
    }
    return;

}
int main() {
    struct node* root = NULL;
    root = createbst(root, 43);
    root = createbst(root, 10);
    root = createbst(root, 79);
    root = createbst(root, 90);
    root = createbst(root, 12);
    root = createbst(root, 54);
    root = createbst(root, 11);
    root = createbst(root, 9);
    root = createbst(root, 50);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    search(root,450);
    deletefrombst(root,50);
    search(root,50);
    return 0;
}
