/******************************
 * Tristan Larkin
 * Project 6
 * Linked List Covid Proteins
 ****************************/

#include <stdio.h>
#include <stdlib.h>

/* Creates a struct that will be typedef as 'Node' 
and will have three fields, an int, a char, and a 
pointer to another node */
struct ListNode
{
  int originalIndex;
  char acid;

  struct ListNode *next;
};
typedef struct ListNode Node;

/* Create the head so we can search and print
Creates the tail to add additional Nodes on the end */
Node *head = NULL;
Node *tail = NULL;

/* Allocates memory for a new node,
uses the parameters to assign values to that
new node, attaches the new node to the tail of the list, 
changes the tail from pointing to the second to last node 
to the last node. */
Node *addNode(int originalIndex1, char acid1)
{
  Node *thisNode = (Node *)malloc(sizeof(Node));

  thisNode->originalIndex = originalIndex1;
  thisNode->acid = acid1;
  thisNode->next = NULL;

  if (tail != NULL)
  {
    tail->next = thisNode;
  }
  tail = thisNode;

  return thisNode;
}

/* Counts how many elements are in the list until NULL is reached */
int length()
{
  Node *current = head;
  int count = 0;
  while (current->next != NULL)
  {
    current = current->next;
    count++;
  }

  return count;
}

/* Frees each item in the linked list */
void freeList()
{
  Node *current = head;

  while (current != NULL)
  {
    Node *prev = current;
    current = current->next;
    free(prev);
  }
}

/* Helper function for printlist().
It will print 10 items then return the next node 
that needs to be printed. */
Node *print10Char(Node *current)
{
  int count = 0;
  while (count < 10 && current->next != NULL)
  {
    printf("%c", (char)(current->acid));

    current = current->next;
    count++;
  }

  return current;
}

/* Prints the linked list and header in the proper format. */
void printList(char *variant)
{
  Node *current = head;
  int row = 0;
  int lengthOfList = length();
  int counter = 0;
  int counter2 = 0;

  printf("Spike protein sequence for %s:\n", variant);

  while (counter2 < lengthOfList)
  {
    counter += 10;
    printf("%10d", counter);
    while (counter % 50 != 0)
    {
      counter += 10;
      if (counter <= lengthOfList - lengthOfList % 10)
      {
        printf(" %10d", counter);
      }
      else
      {
        printf("           ");
      }
    }
    printf("\n");

    counter2 += 10;
    current = print10Char(current);
    while (counter2 % 50 != 0 && counter2 < lengthOfList)
    {
      printf(" ");
      current = print10Char(current);
      counter2 += 10;
    }
    printf("\n");

    row++;
  }
}

/* finds the node with the correct index, then 
attaches the previous node to the following node, 
then frees the node with the index given. */
void deleteNode(int index)
{
  int indexToFind = index;
  Node *current = head;
  Node *prev = head;
  while (current->originalIndex != indexToFind)
  {
    prev = current;
    current = current->next;
  }

  if (current == head)
  {
    head = current->next;
  }
  else
  {
    prev->next = current->next;
  }

  free(current);
}

/* Finds the node and replaces the original acid with the new acid. */
void replaceNode(char oldAcid, char newAcid, int index)
{
  Node *current = head;
  while (current->originalIndex != index)
  {
    current = current->next;
  }
  current->acid = newAcid;
}

/* Main fuction that runs the program. */
int main(int argc, char *argv[])
{
  int numOfDeletes = 0;
  int numOfReplaces = 0;
  int i = 0;

  int *delArgs = (int *)calloc(1, sizeof(int));
  int *repArgs = (int *)calloc(3, sizeof(int));

  int count = 1;
  char c = getchar();
  head = addNode(1, c);

  /* Copies each char into the LinkedList at the proper index */
  while (c != EOF)
  {
    c = getchar();
    if (c == '\n')
    {
      continue;
    }
    count++;
    addNode(count, c);
  }

  /* creates the dynamic arrays for the delete arguments and the replace 
  arguments. */
  while (numOfDeletes + numOfReplaces < argc - 2)
  {
    int tempInt;
    char tempChar1;
    char tempChar2;

    if (sscanf(argv[numOfDeletes + numOfReplaces + 2], "d%d", &tempInt) > 0)
    {
      numOfDeletes++;
      delArgs = (int *)realloc(delArgs, (numOfDeletes) * sizeof(int));
      delArgs[numOfDeletes - 1] = tempInt;
    }

    else if (sscanf(argv[numOfDeletes + numOfReplaces + 2],
                    "%c%d%c", &tempChar1, &tempInt, &tempChar2) > 0)
    {
      numOfReplaces++;
      repArgs = (int *)realloc(repArgs, numOfReplaces * 3 * sizeof(int));
      repArgs[(numOfReplaces - 1) * 3 + 0] = tempChar1;
      repArgs[(numOfReplaces - 1) * 3 + 1] = tempInt;
      repArgs[(numOfReplaces - 1) * 3 + 2] = tempChar2;
    }
  }

  /* Loops delete and replace the specified acids */
  for (i = 0; i < numOfDeletes; i++)
  {
    deleteNode(delArgs[i]);
  }

  for (i = 0; i < numOfReplaces; i++)
  {
    replaceNode(repArgs[3 * i + 0], repArgs[3 * i + 2], repArgs[3 * i + 1]);
  }

  printList(argv[1]);


  /* free the 2 arrays and the list */
  free(delArgs);
  free(repArgs);
  freeList();

  return 0;
}