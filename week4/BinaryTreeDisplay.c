//displaying using queue
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COUNT 10


struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
};


struct node2
{
	int data;
	struct node *addrs_value;
	struct node2 *next;
};
struct node2 *front=NULL,*rear=NULL;

void enqueue(struct node* root3);
void dequeue();
void display();
int is_empty();


struct node* create();
struct node* create_tree(int [], int [], int , int );
void display_Inorder(struct node* node);
void display_Preorder(struct node* node);
void display_Postorder(struct node* node);
int find_index(int arr[], int strt, int end, int value);
int len;
void level_order(struct node* root2);
int find_height(struct node* node);
int arr[100],h;
void insertion(struct node *ptr, int val,int side);

void print_tree(struct node *root);
void display_tree(struct node *root, int space);





void insertion(struct node *ptr, int val,int side){
	int ele;
	struct node *ptr2;
	ptr2=(struct node*)malloc(sizeof(struct node));
	if(side==1){
		ptr->left_child=ptr2;
	}
	if(side==2){
		ptr->right_child=ptr2;
	}

	ptr2->data=val;
	ptr2->left_child=NULL;
	ptr2->right_child=NULL;

	printf("\n Enter left child for %d, (Enter -2 for No Node) : ",val);
	scanf("%d",&ele);
	if(ele!=-2){
		insertion(ptr2,ele,1);
	}
	printf("\n Enter Right child for %d, (Enter -2 for No Node) : ",val);
	scanf("%d",&ele);
	if(ele!=-2){
		insertion(ptr2,ele,2);
	}

}

int find_height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lval = find_height(node->left_child);
        int rval = find_height(node->right_child);

        /* use the larger one */
        if (lval > rval)
            return (lval + 1);
        else
            return (rval + 1);
    }
}


void display_Inorder(struct node* node)
{
    if (node == NULL)
        return;

    display_Inorder(node->left_child);
    printf("%d ", node->data);
    display_Inorder(node->right_child);
}

void display_Preorder(struct node* node){
	 if (node == NULL)
        return;
	printf("%d ", node->data);
	display_Preorder(node->left_child);
    display_Preorder(node->right_child);

}

void display_Postorder(struct node* node)
{
    if (node == NULL)
        return;

    display_Postorder(node->left_child);
    display_Postorder(node->right_child);
    printf("%d ", node->data);
}


void display_tree(struct node* root2, int space)
{
    int i;
	if (root2 == NULL)
        return;

    space += COUNT;
    display_tree(root2->right_child,space);
    printf("\n");
    for ( i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root2->data);
    display_tree(root2->left_child,space);
}


void print_tree(struct node* root)
{
   display_tree(root, 0);
}


void main(){
	int i,j,ele,ch,temp=0;
	struct node* root;
	while(1){
		printf("\n\n 1. Create Binary Tree");
		printf("\n 2. Calculate height");
		printf(" \n 3. Display Inorder traversal");
		printf(" \n 4. Display Preorder traversal");
		printf(" \n 5. Display Postorder traversal ");
		printf("\n 6. Display Binary Tree in Tree Format ");
		printf(" \n 7. Exit");
		printf("\n Enter Your choice:");
		if(scanf("%d",&ch)==1){
			if(ch==1) {
					int val;
					struct node *roott;
					root= (struct node *)malloc(sizeof(struct node));
					printf("\n Enter Root Node value: ");
					scanf("%d",&root->data);
					root->left_child=NULL;
					root->right_child=NULL;
					printf("\n Enter left child for %d (Enter -2 for No Node) : ",root->data);
					scanf("%d",&val);
					if(val!=-2)
					{
						insertion(root,val,1);
					}
					printf("\n Enter Right child for %d (Enter -2 for No Node) : ",root->data);
					scanf("%d",&val);
					if(val!=-2)
					{
						insertion(root,val,2);
					}
			}
			else if(ch==2){
				h=find_height(root);
				printf("\n Height of Binary Tree is : %d",h);
			}
			else if (ch==3){
				printf("\n Inorder Traversal : \n ");
				display_Inorder(root);
			}
			else if(ch==4){
				printf("\n Preorder Traversal : \n ");
				display_Preorder(root);
			}
			else if(ch==5){
				printf("\n Postorder Traversal : \n ");
				display_Postorder(root);
			}
			else if(ch==6){
                    printf("Binary Tree: \n");
				 print_tree(root);
			}

			else if(ch==7){
				break;
			}
			else{
				printf(" \nInvalid choice.. Try again\n");
			}
		}
		else{
			printf("\n Invalid input");
			exit(0);
		}
	}

}


