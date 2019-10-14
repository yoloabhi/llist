#include <stdio.h>
#include <stdlib.h>
int len;
struct node{
int data;
struct node *link;
};
struct node *root;





void append()
{ struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the node data at the end of the list: ");
scanf("%d",&temp->data);
temp->link = NULL;

if(root == NULL)
{
    root = temp;
}
else
{
    struct node *p;
    p=root;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=temp;
}
}








int length(){
int count=0;
struct node *p;
p=root;
while(p!=NULL){
    count++;
    p=p->link;
}
return count;

}





void display(){
struct node *temp;
temp=root;
if(temp==NULL){
    printf("List is empty\n");

}
else{
   while(temp!=NULL){
    printf("%d---->",temp->data);
    temp=temp->link;
}
printf("\n");
}


}
void del(){
int pos;
printf("Enter the position of the item you want to delete");
scanf("%d",&pos);
int count=0;
struct node *temp;
struct node *p;
temp=root;
while(temp!=NULL){
    count++;
    if(count==pos-1){
     p=temp->link;
     temp->link=temp->link->link;

     free(p);


     break;
    }
    if(pos==1){
      p=temp->link;
      root=temp->link;
    free(p);


      break;
    }
    else if(pos==len &&  count==pos-1){
        p=temp->link;
        temp->link=NULL;
        free(p);

        break;

}
    temp=temp->link;
}



}

void add(){
int pos,count=0;
struct node *temp;
printf("Enter the position of the element you wish to enter");
scanf("%d",&pos);
temp=(struct node*)malloc(sizeof(struct node));

printf("Enter the data of the new element");
scanf("%d",&temp->data);
struct node *trav;
trav=root;
while(trav!=NULL){
    count++;
    if(pos==1){
        temp->link=root;
        root=temp;
        break;
         }

    else if(count==pos-1){
        temp->link=trav->link;
        trav->link=temp;
        break;
    }

trav=trav->link;
}




}


void sort(){
struct node *trav;

int i;
int temp;
struct node *tran;
tran =root;

 while(tran->link!=NULL){
trav=root;

 while(trav->link!=NULL){

    if((trav->data)>(trav->link->data)){
      temp=trav->data;
      trav->data=trav->link->data;
      trav->link->data=temp;


      }

  trav=trav->link;
  }


tran=tran->link;
}




}












int main(){

    int o;
    while(1){
     printf("1)Append\n2)Length\n3)Display\n4)Add\n5)Delete\n6)Sort\nPlease enter the option: ");
     scanf("%d",&o);
     switch(o){
     case 1:append();break;
     case 2:len=length();printf("%d\n",len);break;
     case 3:display();break;
     case 4:add();break;
     case 5:del();break;
     case 6:sort();break;

     default:printf("The option doesnt exist");



     }

}
    return 0;
}
