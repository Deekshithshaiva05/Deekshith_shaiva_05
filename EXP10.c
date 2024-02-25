#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *lchild;
    struct bst *rchild;
};
typedef struct bst *NODE;
void create()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct bst));
    printf("Enter the value");
    scanf("%d",temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void insert(NODE root,NODE newroot);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);

void insert(NODE root,NODE newroot)
{
    if(newnode->data < root -> data)
    {
        if(root -> lchild ==NULL)
            root -> lchild = newnode;
        else
            insert(root -> lchild , newnode);
    }
    else
    {
        if(root -> rchild ==NULL)
            root -> rchild = newnode;
        else
            insert(root -> rchild , newnode);
    }
}
void search(NODE root)
{
    int key;
    NODE cur;
    if(root == NULL)
    {
        printf("BST is empty\n");
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    cur = root;
    while(cur != NULL)
    {
        if(cur -> data = key)
            printf("Key elelment is present in bst\n");
            return
            if(cur -> data > key)
                cur = cur -> lchild;
            else
                cur = cur -> rchild;
    }
    printf("\n key element is not found in the bst");
}
void inorder(NODE root)
{
    if(root != NULL)
    {
        inorder(root -> lchild);
        printf("%d\n",root->data);
        inorder(root -> rchild);
    }
}
void preorder(NODE root)
{
    if(root != NULL)
    {
        printf("%d\n",root->data);
        preorder(root->lchild); 
        preorder(root->rchild);
    }
}
void postorder(NODE root)
{
    if(root != NULL)
    {
        postorder(root->lchild); 
        postorder(root->rchild); 
        printf("%d\n",root->data);
    }
}
void main()
{
    int ch,key,val,i,n;
    NODE root = NULL,newnode;
    while(1)
    {
        printf("1.create a BST\n 2.search\n 3.BST traversal \n 4.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of element:");
            scanf("%d",&n);
            for(i=0;i<=n;i++)
            {
                newnode = create();
                if(root = NULL)
                    root = newnode;
                else
                    insert(root,newnode);
            }
            break;
            case 2:search(root);
            break;
            case 3:if(root == NULL)
            {
                printf("tree is empty\n"); 
            }
            else
            {
                printf("\n inorder traversal\n"); 
                inorder(root);
                printf("\n postorder traversal\n"); 
                postorder(root);
                printf("\n preorder traversal\n"); 
                preorder(root);
            }
            break;
            case 4:exit(0);
        }
    }
}