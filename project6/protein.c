/******************************
 * Tristan Larkin
 * Project 6
 * 
 ****************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct listNode
{
  int originalIndex;
  char acid;

  struct listNode *next;
};

typedef struct listNode Node;

Node *head;
Node *tail;

Node *addNode(int originalIndex1, char acid1)
{
  Node *thisNode = (Node *)malloc(sizeof(Node));

  thisNode->originalIndex = originalIndex1;
  thisNode->acid = acid1;
  thisNode->next = NULL;

  tail->next = thisNode;
  tail = thisNode;

  return thisNode;
}

void printList()
{
  Node *current = head;
  while (current->next != NULL)
  {
    printf("%c", (current->acid));
    current = current->next;
  }
  printf("\n");
}

int main()
{
  int count = 1;
  char c = getchar();
  head = (Node *)malloc(sizeof(Node));
  tail = head;
  addNode(1, c);

  while (c != EOF)
  {
    c = getchar();
    if (c == '\n')
    {
      continue;
    }
    count++;
    addNode(count, c);
    printList();
  }
}