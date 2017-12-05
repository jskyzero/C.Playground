#include <stdio.h>
	    int i;
	    int main()
	    {
       extern int i;
	        if (i == 0)
	            printf("scope rules\n");
	    }

