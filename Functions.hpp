//Will contain all the header files for functions.cpp

typedef struct node
{
    long num;
    struct node *pNext;
}Node;

//initializes list
void initList(Node **pList);

//prints out the entire list
void display_list(Node **pList);

//creates a node
Node *makeNode(long newNum);

//inserts node in list in ascending order
void insert(Node **pList, long newNum);

//checks if list is empty
int isempty(Node *pList);

//finds min value in list
long findMin(Node *pList);

//finds max value in list
long findMax(Node *pList);

//finds the median value in the list
long findMedian(Node *pList);

//asks the user which file they wish to look at
//returns ints cooresponding to files
int whichFile();


