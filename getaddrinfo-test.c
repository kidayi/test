#include<netdb.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

int main(int argc,char *argv[]){
	struct addrinfo hints;
	memset(&hints, 0, sizeof (hints));
	
	hints.ai_flags = AI_PASSIVE|AI_ADDRCONFIG;
	hints.ai_family = AF_UNSPEC;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_socktype = SOCK_STREAM;

	struct addrinfo *ai;
	struct addrinfo *next;

	char *domain=NULL;
	
	if(argc>1){
		domain=argv[1];
		hints.ai_flags = AI_ADDRCONFIG|AI_CANONNAME;
	}

	getaddrinfo(domain,"80",&hints,&ai);

	int ipstrLen=50;
	char ipstr[50]="-";

	for (next=ai;next;next=next->ai_next) {
		printf("------------------\r\n");

		printf("addrinfo.ai_canonname:%s\r\n",
			next->ai_canonname?next->ai_canonname:"-");

		printf("addrinfo.ai_family:%d\r\n",next->ai_family);
		printf("addrinfo.ai_addr.sa_family:%d\r\n",next->ai_addr->sa_family);

		if(next->ai_family==AF_INET){
			printf("AF_INET ai_family:%d\r\n",next->ai_addr->sa_family);
			struct sockaddr_in* temp=(struct sockaddr_in*)(next->ai_addr);
			printf("sockaddr_in.sina_port:%d\r\n",ntohs(temp->sin_port));
			
			
			inet_ntop(AF_INET, 
					(void *)&(temp->sin_addr), 
					ipstr,ipstrLen);		
		}else if(next->ai_family==AF_INET6){
			printf("AF_INET6 ai_family:%d\r\n",next->ai_family);
			struct sockaddr_in6* temp=(struct sockaddr_in6*)next->ai_addr;
			printf("sockaddr_in6.sin6_port:%d\r\n",ntohs(temp->sin6_port));
			
			inet_ntop(AF_INET6, 
					(void *)&(temp->sin6_addr), 
					ipstr,ipstrLen);
		}else{
			printf("else ai_family:%d\r\n",next->ai_family);
		}
		
		printf("addr:%s\r\n",ipstr);
	}
	freeaddrinfo(ai);
}