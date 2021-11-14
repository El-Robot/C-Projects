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

Node *print10Char(Node *current)
{
  int count = 0;
  while (count < 10 && current != NULL)
  {
    printf("%c", (char)(current->acid));

    current = current->next;
    count++;
  }

  return current;
}

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

void deleteNode(int index)
{
  Node *current = head;
  Node *prev = NULL;
  while (current->originalIndex != index)
  {
    prev = current;
    current = current->next;
  }
  prev->next = current->next;
}

void replaceNode(char oldAcid, char newAcid, int index)
{
  Node *current = head;
  while (current->originalIndex != index)
  {
    current = current->next;
  }
  current->acid = newAcid;
}

int main(int argc, char *argv[])
{
  int count = 1;
  char c = getchar();
  head = (Node *)malloc(sizeof(Node));
  tail = head;
  head = addNode(1, c);

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

  printList(argv[1]);

  return 0;
}