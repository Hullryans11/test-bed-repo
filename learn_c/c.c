#include <stdio.h>


int main (int argc, char *argv[]){

	int i = 23;
	int *pI = &i;
	printf("\nthe current afdress is %p\n", pI);


	double d = 33.4;
	double *pD = &d;

	printf("\nthe current afdress is %p\n", pI);

	int x = 0;
	int y = 34;

	for(int z = 0; z <5; z++){
		x += 3;
		y*= 4;
	}

return 0;
}


