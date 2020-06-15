//Blajo

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "ArboreRegasire.h"

void Initializare(NodArboreDeRegasire *Nod)

{

	//ATENTIE, aceasta functie trebuie apelata cu *Nod deja alocat

	char c;

	for (c = 'A'; c <= '['; c++)

		Nod->alfabet[c - 'A'] = NULL;

}



void Atribuie(NodArboreDeRegasire *Nod, char c, char *p)

{

	Nod->alfabet['[' - 'A'] = (char*)p;

}



NodArboreDeRegasire *Valoare(NodArboreDeRegasire *Nod, char c)

{

	return Nod->alfabet[c - 'A'];

}



void NodNou(NodArboreDeRegasire *Nod, char c)

{

	Nod->alfabet[c - 'A'] = (NodArboreDeRegasire *)malloc(sizeof(struct NodArboreDeRegasire));

	Initializare(Nod->alfabet[c - 'A']);

}



void Adauga(char *x, NodArboreDeRegasire *cuvinte, char * expl)  //x=cuvantul, cuvinte=radacina arborelui de regasire



{



	int i;



	NodArboreDeRegasire *t;



	t = cuvinte;



	//TO DO: de adaugat cod pentru parcurgerea cuvantului, litera cu litera

	for (i = 0; i < strlen(x);i++)

	{



		if (Valoare(t, x[i]) == NULL) //nodul curent nu are fiu pentru caracterul x[i], deci se creaza unul nou



			NodNou(t, x[i]);



		t = Valoare(t, x[i]); //avansez in arborele de regasire



	}

	Atribuie(t, '[', expl); //caracterul [ pointeaza spre explicatie



}



void cauta(NodArboreDeRegasire *rad, char *cuv)

{

	int i;

	i = 0;

	NodArboreDeRegasire *t;

	t = rad;



	while (Valoare(t, cuv[i]) != NULL && i<strlen(cuv))

	{

		t = Valoare(t, cuv[i]);

		i++;

	}

	if (t == NULL)

		printf("Nu exista cuv!");

	else

		printf("%s\n",t->alfabet[26]);

}



int maxim;



int inaltime(NodArboreDeRegasire *rad,int h){

	NodArboreDeRegasire *t;

	t = rad;

	int i;

	for (i = 0; i < 26;i++)

	if (t->alfabet[i]!=NULL){

		h++;

		//t = Valoare(t, t->alfabet[i]);

		inaltime(t->alfabet[i], h);



	   }

	else

	   if (t->alfabet['['-'A']!=NULL)

		  if (h>maxim)

			  maxim = h;

return maxim;

}



int main()

{

	NodArboreDeRegasire *rad;

	rad = (NodArboreDeRegasire *)malloc(sizeof(NodArboreDeRegasire));

	char *cuv;

	char *exp;

	cuv = (char*)malloc(30*sizeof(char));

	exp = (char*)malloc(200 * sizeof(char));

	cuv = "ANA";

	exp = "nume romanesc";

	Initializare(rad);

	Adauga(cuv, rad, exp);

	cuv = "ANCA";

	exp = "alt nume romanesc";

	Adauga(cuv, rad, exp);

	Adauga("ANSOA", rad, "peste");

	cauta(rad, "ANA");

	printf("%d\n",inaltime(rad,0));

}

// C implementation of search and insert operations
// on Trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isEndOfWord = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    struct TrieNode *root = getNode();

    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );

    return 0;
}

// C++ implementation to count words in a trie
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
        pNode->isLeaf = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int length = strlen(key);

    struct TrieNode *pCrawl = root;

    for (int level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// Function to count number of words
int wordCount(struct TrieNode *root)
{
    int result = 0;

    // Leaf denotes end of a word
    if (root -> isLeaf)
        result++;

    for (int i = 0; i < ALPHABET_SIZE; i++)
      if (root -> children[i])
         result += wordCount(root -> children[i]);

    return result;
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    char keys[][8] = {"the", "a", "there", "answer",
                     "any", "by", "bye", "their"};


    struct TrieNode *root = getNode();

    // Construct Trie
    for (int i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);

    cout << wordCount(root);

    return 0;
}

// CPP program to display content of Trie
#include <iostream>
#include <string.h>
#define alpha_size 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

using namespace std;

// Trie node
struct TrieNode
{
    struct TrieNode* children[alpha_size];

    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* createNode()
{
    struct TrieNode* pNode = new TrieNode;

    for (int i = 0; i < alpha_size; i++)
        pNode->children[i] = NULL;

    pNode->isLeaf = false;

    return pNode;
};

// function to insert a node in Trie
void insert_node(struct TrieNode* root, char* key)
{
    int level;
    int length = strlen(key);
    struct TrieNode* pCrawl = root;

    for (level = 0; level < length; level++)
    {
        int index = key[level] - 'a';

        if (pCrawl->children[index] == NULL)
            pCrawl->children[index] = createNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isLeaf = true;
}

// function to check if current node is leaf node or not
bool isLeafNode(struct TrieNode* root)
{
    return root->isLeaf != false;
}

// function to display the content of Trie
void display(struct TrieNode* root, char str[], int level)
{
    // If node is leaf node, it indiicates end
    // of string, so a null charcter is added
    // and string is displayed
    if (isLeafNode(root))
    {
        str[level] = '\0';
        cout << str << endl;
    }

    int i;
    for (i = 0; i < alpha_size; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

// Driver program to test above functions
int main()
{
    // Keys to be inserted in Trie
    char keys[][8] = { "the", "a", "there", "answer",
                       "any", "by", "bye", "their" };

    struct TrieNode* root = createNode();

    // Inserting keys in Trie
    for (int j = 0; j < ARRAY_SIZE(keys); j++)
        insert_node(root, keys[j]);

    int level = 0;
    char str[20];

    // Displaying content of Trie
    cout << "Content of Trie: " << endl;
    display(root, str, level);
}


#include <stdio.h>

// define character size
// currently Trie supports lowercase English characters (a - z)
#define CHAR_SIZE 26

// A Trie node
struct Trie
{
    int isLeaf;    // 1 when node is a leaf node
    struct Trie* character[CHAR_SIZE];
};

// Function that returns a new Trie node
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = 0;

    for (int i = 0; i < CHAR_SIZE; i++)
        node->character[i] = NULL;

    return node;
}

// Iterative function to insert a string in Trie.
void insert(struct Trie* *head, char* str)
{
    // start from root node
    struct Trie* curr = *head;
    while (*str)
    {
        // create a new node if path doesn't exists
        if (curr->character[*str - 'a'] == NULL)
            curr->character[*str - 'a'] = getNewTrieNode();

        // go to next node
        curr = curr->character[*str - 'a'];

        // move to next character
        str++;
    }

    // mark current node as leaf
    curr->isLeaf = 1;
}

// Iterative function to search a string in Trie. It returns 1
// if the string is found in the Trie, else it returns 0
int search(struct Trie* head, char* str)
{
    // return 0 if Trie is empty
    if (head == NULL)
        return 0;

    struct Trie* curr = head;
    while (*str)
    {
        // go to next node
        curr = curr->character[*str - 'a'];

        // if string is invalid (reached end of path in Trie)
        if (curr == NULL)
            return 0;

        // move to next character
        str++;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return 1
    return curr->isLeaf;
}

// returns 1 if given node has any children
int haveChildren(struct Trie* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return 1;    // child found

    return 0;
}

// Recursive function to delete a string in Trie.
int deletion(struct Trie* *curr, char* str)
{
    // return if Trie is empty
    if (*curr == NULL)
        return 0;

    // if we have not reached the end of the string
    if (*str)
    {
        // recurse for the node corresponding to next character in
        // the string and if it returns 1, delete current node
        // (if it is non-leaf)
        if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
            deletion(&((*curr)->character[*str - 'a']), str + 1) &&
            (*curr)->isLeaf == 0)
        {
            if (!haveChildren(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else {
                return 0;
            }
        }
    }

    // if we have reached the end of the string
    if (*str == '\0' && (*curr)->isLeaf)
    {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(*curr))
        {
            free(*curr); // delete current node
            (*curr) = NULL;
            return 1; // delete non-leaf parent nodes
        }

        // if current node is a leaf node and have children
        else
        {
            // mark current node as non-leaf node (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0;       // don't delete its parent nodes
        }
    }

    return 0;
}

// Trie Implementation in C - Insertion, Searching and Deletion
int main()
{
    struct Trie* head = getNewTrieNode();

    insert(&head, "hello");
    printf("%d ", search(head, "hello"));       // print 1

    insert(&head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // print 1

    printf("%d ", search(head, "helll"));       // print 0 (Not present)

    insert(&head, "hell");
    printf("%d ", search(head, "hell"));        // print 1

    insert(&head, "h");
    printf("%d \n", search(head, "h"));         // print 1 + newline

    deletion(&head, "hello");
    printf("%d ", search(head, "hello"));       // print 0 (hello deleted)
    printf("%d ", search(head, "helloworld"));  // print 1
    printf("%d \n", search(head, "hell"));      // print 1 + newline

    deletion(&head, "h");
    printf("%d ", search(head, "h"));           // print 0 (h deleted)
    printf("%d ", search(head, "hell"));        // print 1
    printf("%d\n", search(head, "helloworld")); // print 1 + newline

    deletion(&head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // print 0
    printf("%d ", search(head, "hell"));        // print 1

    deletion(&head, "hell");
    printf("%d\n", search(head, "hell"));       // print 0 + newline

    if (head == NULL)
        printf("Trie empty!!\n");               // Trie is empty now

    printf("%d ", search(head, "hell"));        // print 0

    return 0;
}

