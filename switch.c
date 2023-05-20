//singly linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *insert_at_begin(struct node *head,int n){
    struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
temp->data = n;
temp->next = NULL;
temp->next = head;
head = temp;
return head;
}

struct node *insert_at_end(struct node *head,int n){
  struct node *temp,*ptr = head;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = n;
  temp->next = NULL;
  if(head == NULL)
  head = temp;
  else{
  while(ptr->next!=NULL)
  ptr = ptr->next;
  ptr->next =temp;
  }
  return head;
  }
struct node *delete(struct node *head,int n){
    struct node *ptr = head;
    if(ptr->data == n)
    {
        ptr = ptr->next;
        head = ptr;
    }
    else
    {
    while(ptr->next!=NULL && ptr->next->data!=n){
        ptr = ptr->next;
    }
    if(ptr->next == NULL)
    printf("Data is not found in any node of linkedlist");
    else{
        ptr->next = ptr->next->next;
    }
    }
    return head;
}
void search(struct node *head,int num){
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr = head;
  int c=1;
  while(ptr->data!=num){
    ptr= ptr->next;
    c++;
  }
    printf("No. is present in %d node\n",c);

}
void display(struct node *ptr){
while(ptr!=NULL)
{
     printf("%d\n",ptr->data);
    ptr = ptr->next;
   
}
}
struct node *reverse(struct node *head){
    struct node *prev = NULL, *frwd = NULL,*ptr = head;
    while(ptr!=NULL)
    {
        frwd = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = frwd;
    }
    ptr = prev;
    head = ptr;
    return head;
}
int main()
{
   
    struct node *head = NULL;
    int n,c;
    char ch;
    printf("Enter choice if you want to run program than enter y else n(y/n): ");
    fflush(stdin);
    scanf("%c", &ch);
    while(ch == 'y'){
        printf("Enter choice 1)Insert_begin , 2)Insert_end , 3)Delete , 4)Reverse , 5)Display , 6)exit ");
        scanf("%d",&c);
    switch(c){
         case 1:
         printf("Enter data: ");
         scanf("%d",&n);
         head = insert_at_begin(head,n);
         break;
         case 2:
         printf("Enter data: ");
         scanf("%d",&n);
         head = insert_at_end(head,n);
         break;
         case 3:
          printf("Enter data to be deleted: ");
          scanf("%d",&n);
         head = delete(head,n);
         break;
         case 4:
        head = reverse(head);
        break;
        case 5:
        printf("Dispalying Linked list\n");
        display(head);
        break;
        case 6:
        printf("Program closed");
        ch = n;
        break;
    }
    }
return 0;
}