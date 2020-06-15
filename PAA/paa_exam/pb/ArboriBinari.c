#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
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
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    Node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->key << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->key;
    else
      cout << "No Successor";
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}Node;

Node* root;

Node* createNode(int key){
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void addNode(Node** Root, int key){
	if ((*Root) == NULL)
		(*Root) = createNode(key);
	else{
		if (key < (*Root)->key)
			addNode(&((*Root)->left), key);
		else
			addNode(&((*Root)->right), key);
	}
}

void listInPreorder(Node* Root){
	if (Root != NULL){
		printf("%d ", Root->key);
		listInPreorder(Root->left);
		listInPreorder(Root->right);
	}
}

void listInInorder(Node* Root){
	if (Root != NULL){
		listInInorder(Root->left);
		printf("%d ", Root->key);
		listInInorder(Root->right);
	}
}

void listInPostorder(Node* Root){
	if (Root != NULL){
		listInPostorder(Root->left);
		listInPostorder(Root->right);
		printf("%d ", Root->key);
	}
}

int main()
{
	int n, i, value;
	printf("Introduceti numaruul de noduri: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &value);
		addNode(&root, value);
	}
	printf("\nPreordine:\n");
	listInPreorder(root);
	printf("\nInordine:\n");
	listInInorder(root);
	printf("\nPostordine:\n");
	listInPostorder(root);

	getch();
	getch();
	return 0;
}

#include<stdlib.h>
#include<stdio.h>
struct ab *r;
int i, n, x;
typedef struct ab{
	int cheie;
	struct ab* st;
	struct ab* dr;

} AB;
void adaugare(int x, struct ab** r){
	if ((*r) != NULL){
		if (x < (*r)->cheie)
			adaugare(x, &((*r)->st));
		else
			adaugare(x, &((*r)->dr));
	}
	else
	{ 
	(*r) = (struct ab*)malloc(sizeof(struct ab));
	(*r)->cheie = x;
	(*r)->st = NULL;
	(*r)->dr = NULL;
	}
}
	void pre(struct ab* r){
		if (r != NULL){
			printf("%d", r->cheie);
			pre(r->st);
			pre(r->dr);
		}
	}
	void in(struct ab* r){
		if (r != NULL){
			in(r->st);
			printf("%d", r->cheie);
			in(r->dr);
		}
	}
	void post(struct ab* r){
		if (r != NULL){
			post(r->st);
			post(r->dr);
			printf("%d", r->cheie);
			
		}
	}
	int main(){
		struct ab *arbore = NULL;
		printf("Numarul de noduri este ");
		scanf("%d", &n);
		for (i = 1; i <= n; i++){
		scanf("%d", &x);
		adaugare(x, &arbore);
	}
		printf("Arborele in preordine este\n");
		pre(arbore);
		printf("\nArborele in inordine este\n");
		in(arbore);
		printf("\nArborele in postordine este\n");
		post(arbore);
		
		
		return 0;
	}
	
