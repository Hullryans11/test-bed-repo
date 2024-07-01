#include <stdio.h>
#include <ctype.h>


//functions
void print_array_of_str(int argc, char *argv[]){
		char header[] = {"\nargument: "};
		for(int i = 0; i < argc; i++){
			printf("%s", header);
			printf("%c", argv[i][2]);
		}
	}



int main (int argc, char *argv[]){
/*
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
*/


	char *str = "0123\0";
	for(int i = 0; i <8; i++){
	printf("\n\%c", str[i]);
	}




return 0;
}



