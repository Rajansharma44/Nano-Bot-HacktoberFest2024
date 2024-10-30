#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
  int data;
  struct node *next;
}NODE;

int count = 0;

NODE *createnode(int data)
{
  NODE *nn = (NODE *)malloc(sizeof(NODE));
  if(!nn)
  {
    printf("Memory allocation failed!");
    exit(1);
  }
  nn->data = data;
  nn->next = NULL;
  return nn;
}

NODE *insertLast(NODE *head, int data)
{
  NODE *nn = createnode(data);
  if(head == NULL)
  {
    head = nn;
  }
  else
  {
    NODE *temp = head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = nn;
  }
  printf("New node inserted successfully!\n");
  count++;
  return head;
}

NODE *insertStart(NODE *head, int data)
{
  NODE *nn = createnode(data);
  if(head == NULL)
  {
    head = nn;
  }
  else
  {
    nn->next = head;
    head = nn;
  }
  printf("New node inserted successfully!\n");
  count++;
  return head;
}

NODE *insertMid(NODE *head, int data, int pos)
{
  if(pos == 1) //pos = 1 is starting
  {
    return insertStart(head, data);
  }
  else if(pos > count +1) // pos is 2 more than last node position
  {
    printf("Position out of bouds!\n");
    printf("Number of nodes: %d\n", count);
    printf("Position asked to insert in: %d\n", pos);
  }
  else if(pos == count+1) // pos is the last node
  {
    return insertLast(head, data);
  }
  else //pos is in between the list
  {
    NODE *temp = head;
    for(int i=1; i<pos-1 && temp != NULL; i++)
    {
      temp = temp->next;
    }
    NODE *nn = createnode(data);
    nn->next = temp->next;
    temp->next = nn;
    printf("New node inserted successfully!\n");
    count++;
  }
  return head;
}

NODE *deleteStart(NODE *head)
{
  if(head == NULL)
  {
    printf("The list is already empty!!\n");
    return head;
  }
  NODE *temp = head;
  head = head->next;
  temp->next = NULL;
  free(temp);
  temp = NULL;
  printf("Node deleted successfully!\n");
  count--;
  return head;
}

NODE *deleteLast(NODE *head)
{
  if(head == NULL)
  {
    printf("List is already empty!!\n");
    return head;
  }
  if(head->next == NULL)
  {
    free(head);
    head = NULL;
    count--;
    printf("Node deleted successfully!\n");
    return head;
  }
  NODE *temp = head;
  while(temp->next->next != NULL)
  {
    temp = temp->next;
  }
  NODE *temp1 = temp->next;
  free(temp1);
  temp1 = NULL;
  temp->next = NULL;
  printf("Node deleted successfully!\n");
  count--;
  return head;
}

NODE *deleteMid(NODE *head, int pos)
{
  if(pos == 1)
  {
    return deleteStart(head);
  }
  else if(pos == count)
  {
    return deleteLast(head);
  }
  else if(pos>count)
  {
    printf("Position out of bounds!!\n");
    return head;
  }
  else
  {
    NODE *temp = head;
    for(int i=1; i<pos-1; i++)
    {
      temp = temp->next;
    }
    NODE *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next = NULL;
    free(temp1);
    temp1 = NULL;
    printf("Node deleted successfully!\n");
    count--;
    return head;
  }
}

void display(NODE *head)
{
  if(head == NULL)
  {
    printf("NULL\n");
    return;
  }
  NODE *temp = head;
  while(temp != NULL)
  {
    printf("%d -> ", (temp->data));
    temp = temp->next;
  }
  printf("NULL\n");
}

void Search(NODE *head, int data)
{
  int result = 1;
  NODE *temp = head;
  while(temp != NULL)
  {
    if(temp->data == data)
    {
      printf("%d found in position: %d\n", data, result);
      return;
    }
    temp = temp->next;
    result++;
  }
  printf("Element %d not in list!\n", data);
}

int main()
{
  NODE *head = NULL;
  int choice, data, pos;
  do
  {
    printf("1. Insert Start\n");
    printf("2. Insert Last\n");
    printf("3. Insert Mid\n");
    printf("4. Delete Start\n");
    printf("5. Delete Last\n");
    printf("6. Delete Mid\n");
    printf("7. Display\n");
    printf("8. Search\n");
    printf("9. Exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      {
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        head = insertStart(head, data);
        break;
      }
      case 2:
      {
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        head = insertLast(head, data);
        break;
      }
      case 3:
      {
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the postion to be inserted in: ");
        scanf("%d", &pos);
        head = insertMid(head, data, pos);
        break;
      }
      case 4:
      {
        head = deleteStart(head);
        break;
      }
      case 5:
      {
        head = deleteLast(head);
        break;
      }
      case 6:
      {
        printf("Enter the postion to be deleted at: ");
        scanf("%d", &pos);
        head = deleteMid(head,pos);
        break;
      }
      case 7:
      {
        display(head);
        break;
      }
      case 8:
      {
        printf("Enter data to be searched: ");
        scanf("%d", &data);
        Search(head, data);
        break;
      }
      case 9:
      {
        printf("Exiting!...\n");
        exit(0);
        break;
      }
      default:
      {
        printf("Invalid choice! Choose 1 to 9!\n");
        break;
      }
    }
  }while(choice!=9);
  return 0;
}