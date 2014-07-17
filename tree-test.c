#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node{
	Node *children[26];
	unsigned int isEnd:1;
} rootNode;

typedef struct NodeList{
	Node **nodes;
	int unusedStart;
	int len;
} NodeList;

NodeList nodeList;

Node *addNode(){
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(!newNode){
		return NULL;
	}
	
	if(nodeList.unusedStart>=(nodeList.len-1)){
		printf("in realloc\r\n");
		
		Node **new=(Node **)realloc(nodeList.nodes,
				nodeList.len*2*sizeof(Node*));
		
		if(!new){
			free(newNode);
			return NULL;
		}

		nodeList.nodes=new;
		nodeList.len*=2;
	}

	nodeList.nodes[nodeList.unusedStart++]=newNode;
	
	printf("unusedStart %d \r\n",nodeList.unusedStart);
	
	return newNode;
}

int query(char *str){
	Node *p=&rootNode;
	char *temp=str;

	for(;*temp!='\0';temp++){
		if(!(p=p->children[*temp-'a'])){
			printf("in query %d\r\n",temp-str);
			return 0;
		}
	}

	printf("in query %d\r\n",temp-str);
	
	if(p->isEnd){
		return 1;
	}else{
		return 0;
	}
}

int add(char *str){
	Node *p=&rootNode;
	char *temp=str;

	for(;*temp!='\0';temp++){
		if(!p->children[*temp-'a']){
			Node *newNode=addNode();
			
			if(!newNode){
				return 0;
			}
			
			memset(newNode,0,sizeof(Node));
			
			p->children[*temp-'a']=newNode;
		}

		p=p->children[*temp-'a'];
		
	}
	
	p->isEnd=1;
	
	printf("in add %d\r\n",temp-str);
	return 1;
}

int init(){
	Node **newStart=(Node **)malloc(sizeof(Node*)*5);
	if(!newStart){
		return 0;
	}

	nodeList.nodes=newStart;
	nodeList.unusedStart=0;
	nodeList.len=5;
	return 1;
}

int destructor(){
	printf("in destructor unusedStart %d \r\n",nodeList.unusedStart);
	for(;nodeList.unusedStart>0;){
		free(nodeList.nodes[--nodeList.unusedStart]);
	}
	
	free(nodeList.nodes);
	
	memset(&rootNode,0,sizeof(Node));
	memset(&nodeList,0,sizeof(NodeList));
}

int main(int argc,char *argv[]){
	int status=init();
	if(!status){
		printf("init return 0");
	}

	add("pupupoiu");
	add("ad");
	add("asdfuojadfqpweiurqpoiwuer");
	

	printf("%d\r\n",query("asdfuojadfqpweiurqpoiwuer"));
	printf("%d\r\n",query("as"));
	printf("%d\r\n",query("pupupoiu"));
	printf("%d\r\n",query("bcd"));
	printf("%d\r\n",query("ad"));
	
	destructor();
}


