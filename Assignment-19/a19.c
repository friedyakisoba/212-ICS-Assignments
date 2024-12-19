// Hans Cacalda
// November 16, 2024
/*  Generates a linked list with a random element from 25 -75 with each element being random as well from 0 - 100.
    It then calculates the total sum, count, and the average. 
    Also implemented some memory allocation just in case of creation failurs and memory leaks.
 */

#include <stdio.h>
#include <stdlib.h>
//  time library for the random number generator
#include <time.h>

// node structure for the llist
struct Node
{
    // declaraation for the integer stored in the node
    int number;
    // pointer decleration for the next node in the list
    struct Node *nextNode;
};

// new node function
struct Node *createNode(int newNumber)
{
    // memore allocation for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // assign number to the node
    newNode->number = newNumber;
    // initialize the next pointer
    newNode->nextNode = NULL;
    // return the pointer to the new node
    return newNode;
}

// add a node to the end
void addNodeToEnd(struct Node **listHead, int newNumber)
{
    // new node creation
    struct Node *newNode = createNode(newNumber);
    // checks if the list is empty
    if (*listHead == NULL)
    {
        // if it is make the new node the head of the list
        *listHead = newNode;
    }
    else
    {
        // if not start at the head then move through until the end is reached
        struct Node *currentNode = *listHead;
        while (currentNode->nextNode != NULL)
        {
            // moves to the next node
            currentNode = currentNode->nextNode;
        }
        // links the new node at the end of the list
        currentNode->nextNode = newNode;
    }
}

// function for the sum
int calculateSum(struct Node *listHead)
{
    // initialize the sum to 0
    int sumOfNumbers = 0;
    // start at the head of the list
    struct Node *currentNode = listHead;
    // moves through the list until the end is reached
    while (currentNode != NULL)
    {
        // add the current nodes number to the sum
        sumOfNumbers += currentNode->number;
        // moves on to the next node
        currentNode = currentNode->nextNode;
    }
    // returns the the total sum
    return sumOfNumbers;
}

// node count function
int countNodes(struct Node *listHead)
{
    // initialize the node counter to 0
    int nodeCount = 0;
    // start at the head of the list + moves through the list until the end is reached
    struct Node *currentNode = listHead;
    while (currentNode != NULL)
    {
        // node counter increment
        nodeCount++;
        // moves to the next node
        currentNode = currentNode->nextNode;
    }
    // returns the total number of nodes
    return nodeCount;
}

// linked list print function
void printLinkedList(struct Node *listHead)
{
    // start at the head of the list + moves through the list until the end is reached
    struct Node *currentNode = listHead;
    while (currentNode != NULL)
    {
        // print the number stored in the current node
        printf("%d, ", currentNode->number);
        // moves to the next node
        currentNode = currentNode->nextNode;
    }
    // prints a newline at the end
    printf("\n");
}

// remove memory function
void freeLinkedList(struct Node *listHead)
{
    // pointer to keep track of the current node
    struct Node *currentNode;
    // moves through the list until all the memory is free
    while (listHead != NULL)
    {
        // saves the current node
        currentNode = listHead;
        // moves to the next node + frees the memory of the current node
        listHead = listHead->nextNode;
        free(currentNode);
    }
}

int main()
{
    // initialize the linked list as empty 
    struct Node *linkedListHead = NULL;

    // declaration to store the total number of elements in the list
    int totalNumbersInList, index;

    // seeding random  number generator based on the time
    srand(time(NULL));

    // random element number generator between 25 and 75
    totalNumbersInList = (rand() % 51) + 25;
    for (index = 0; index < totalNumbersInList; index++)
    {
        // random number generatorfor 0-100 tehn add them to the list
        addNodeToEnd(&linkedListHead, rand() % 101);
    }


    // print the list + function call to print all elements
    printf("The list is: ");
    printLinkedList(linkedListHead);

    // calculates the sum of all numbers in the list + count the number of nodes in the list
    int totalSumOfNumbers = calculateSum(linkedListHead);
    int totalNodeCount = countNodes(linkedListHead);

    // calculate the average and converts it to float 
    float averageOfNumbers = (float)totalSumOfNumbers / totalNodeCount;

    // print the total sum
    printf("sum = %d\n", totalSumOfNumbers);
    // print the total number of nodes
    printf("count = %d\n", totalNodeCount);
    // print the average, formatted to 2 decimal places
    printf("average = %.2f\n", averageOfNumbers);

    // remove memory for all nodes in the list
    freeLinkedList(linkedListHead);

    // ran succesfully 
    return 0;
}
