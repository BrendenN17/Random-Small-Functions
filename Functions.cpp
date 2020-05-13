//will contain all functions used to calculate min, max, median, and run- time

//initializes list
void initList(Node **pList)
{
    //sets List head pointer to nullptr
    *pList = nullptr;
}

//prints the list out
void display_list(Node **pList)
{
    Node *pCur = nullptr;
    if (isempty(*pList))
    {
        cout << "List is empty" << endl;
    }
    else
    {
        pCur = *pList;
        while (pCur != nullptr)
        {
            cout << pCur->num << endl;
            pCur = pCur->pNext;
        }
    }
    
}

//creates a node
Node *makeNode(long newNum)
{
    //creating new node and setting pointer to nullptr
    Node *pMem = nullptr;
    
    //allocating space on the heap for the node
    pMem = (Node *) malloc(sizeof(Node));
    
    if (pMem != nullptr)
    {
        //space allocated successfully
        //set data in node
        pMem->num = newNum;
        pMem->pNext = nullptr;
        //sets all pointers in node to NULL
    }
    return pMem;
}

//inserts node in list in same order as file
void insert(Node **pList, long newNum)
{
    Node *pCur = nullptr, *pMem = nullptr;
    
    //creating a new node with correct data
    pMem = makeNode(newNum);
    //checking if empty list
    if (isempty(*pList))
    { //yes list is empty
        *pList = pMem;
    }
    else//at least 1 item in list
    {
        //currently at start of list
        pCur = *pList;//1st item

        //loops until end of list
        while (pCur->pNext != nullptr)
        {

            //advancing to next node
            pCur = pCur->pNext;
        }
        //will be at end of list now. time to insert
        pCur->pNext = pMem;
    }
    
}

//checks if list is empty
int isempty(Node *pList)
{
    return (pList == nullptr);
}

//finds min value in list
long findMin(Node *pList)
{
    Node *pCur = nullptr;
    long min = 10000;
    pCur = pList;

    while (pCur != nullptr)
    {
        if (pCur->num < min)
        {
            min = pCur->num;
        }
        pCur = pCur->pNext;
    }
    return min;
}

//finds max value in list
long findMax(Node *pList)
{
    Node *pCur = nullptr;
    long max = -10000;
    pCur = pList;

    while (pCur->pNext != nullptr)
    {
        if (pCur->num > max)
        {
            max = pCur->num;
        }
        pCur = pCur->pNext;
    }
    return max;
}

//finds the median value in the list
long findMedian(Node *pList)
{
    Node *pCur = nullptr;
    long median = 0;
    int count = 0;
    
    //counting all items in list
    pCur = pList;
    while (pCur->pNext != nullptr)
    {
        count++;
        pCur = pCur->pNext;
    }

    
    if (count % 2 == 0)//even # of items in list. 2 median values
    {
        int helpnum = 0;
        int helpnum2 = 0;
        count = count / 2;
        pCur = pList;
        while (count != 1)
        {
            count--;
            pCur = pCur->pNext;
        }
        helpnum = pCur->num;
        helpnum2 = pCur->pNext->num;
        median = ceil((helpnum + helpnum2) / 2);
    }
    else//odd # of items in list. 1 median value
    {
        count = ceil(count / 2);
        pCur = pList;
        while (count != 0)
        {
            count--;
            pCur = pCur->pNext;
        }
        median = pCur->num;
    }
    
    return median;
}

//asks the user which file they wish to look at
//returns ints cooresponding to files
int whichFile()
{
    int which = 0;
    //forces user to keep entering an int until they enter 1 or 2
    while (which != 1 && which != 2)
    {
    std::cout << "which file would you like to open?" << std::endl << "Press 1 for input file 1 or 2 for input file 2" << std::endl;
        std::cin >> which;
    }
    //returns 1 for inputfile1 or 2 for inputfile2
    return which;
}
