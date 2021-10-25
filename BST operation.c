#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * root=NULL;
void insert(int n)
{
    struct node * temp;
    struct node * parent;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node * current;
        current=root;
        while(current)
        {
            parent=current;
            if(temp->data > current->data)
            {
                current=current->right;
            }
            else
            {
                current=current->left;
            }
        }
        if(temp->data>parent->data)
        {
           parent->right=temp;
        }
        else
        {
            parent->left=temp;
        }
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    struct node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d \t",T->data);
        inorder(T->right);
    }
}
void preorder(struct node *T)

{

    if(T!=NULL)

    {

        printf("%d \t",T->data);

        preorder(T->left);

        preorder(T->right);

    }

}
void postorder(struct node *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d \t",T->data);
    }
}
int main()
{
    int n,a,choice,x;
    do
    {
        printf("\nEnter choice : \n");
        printf("1.Insert\n2.delete node having No Child\n3.Inorder traversal\n4.Preorder traversal\n5.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data you want to insert : ");
                scanf("%d",&n);
                insert(n);
                printf("%d Node is inserted\n",n);
                break;
            case 2:
                printf("Enter data you want to delete : ");
                scanf("%d",&a);
                root = deleteNode(root,a);
                printf("Deletion of %d element having no child is done\n",a);
                break;
            case 3:
                printf("Inorder BST is \n");
                inorder(root);
                break;
             case 4:

                printf("preorder BST is \n");

                preorder(root);
             
                break;
            case 5:
               printf("postorder BST is \n");
               postorder(root);
               break;
            case 6:
                return(1);
                break;
        }
    }while(1);
}
