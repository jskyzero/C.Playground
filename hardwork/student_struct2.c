#include<stdio.h>
int main() {
	struct student{
		char * name;
		char * marks;
	};
	 struct student sa = {
	 	"abc",
	 	"87"
	 };
	 printf("%s",sa.marks);
	 printf("%s",(&sa)->name);
	
}
