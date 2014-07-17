#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node{
	char str[20];
	Node *next;
};

Node *queue=NULL;

void init(){
	Node *curr=NULL;
	int i=0;
	for(;i<10;i++){
		Node *newNode=(Node*)malloc(sizeof(Node));
		snprintf(newNode->str,20,"data-%d",i);
		newNode->next=NULL;
		
		if(!i){
			curr=newNode;
			queue=curr;
		}else{
			curr->next=newNode;
			curr=newNode;
		}
	}
}

void list(){
	printf("----------------\r\n");
	Node *curr=queue;
	while(curr){
		printf("%s\r\n",curr->str);
		curr=curr->next;
	}
}

void removeNode(char *str){
	if(!str){
		return;
	}
	
	Node **curr=&queue;
	
	while(*curr){
		if(strcmp((*curr)->str,str)==0){
			Node *temp=*curr;
			*curr=(*curr)->next;
			free(temp);
		}else{
			curr=&((*curr)->next);
		}
	}
}

int main(int argc,char *argv[]){
	init();
	list();
	removeNode("data-3");
	list();
	removeNode("data-4");
	removeNode("data-2");
	removeNode("data-5");
	removeNode("data-9");
	list();
}
