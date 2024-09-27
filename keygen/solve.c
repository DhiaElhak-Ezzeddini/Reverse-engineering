#include <stdio.h>
#include <strings.h>
int main(void){
	unsigned char name[] = "aaaaaaaaaaaaaaaaaa" ;
        unsigned char pass[4] ; 
	printf("cracked key : ") ; 	
	for (int i=0 ; i<sizeof(name) ; i++){
		char s = (name[i] ^ 0x1)  + (char)i ; 
		printf("%c",s) ; 
	} ; 
	printf("\npassword : %s" , name) ; 
	return 0 ;
};



