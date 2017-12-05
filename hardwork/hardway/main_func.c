#include<stdio.h>
int i;
int main() {
	while(i<=5){
		printf("A\n");
		i++;
		main();
	}
	
	return 0;
} 
