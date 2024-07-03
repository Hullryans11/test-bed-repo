#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA
#define MAX_ROWS 100


//Defines the components of an address object, will be used a a record in the database
struct Address{
int id;
int set; //
char name[MAX_DATA];
char email[];
};

//Struct that defines the components of a database. capable of holding 100 records of the address object
struct Database{
  struct Address rows[MAX_ROWS];
};

struct
