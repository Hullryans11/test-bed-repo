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

//Structure containing database and storage medium , in this case a file
struct Connection{
FILE *file;
struct Database db;
};


//BEGIN FUNCTIONS LISTS

//function is called when a error is identified. prints error mesage to STDERR using a function from the errno.h header file
//if the error is not compatible with errno.h or is not flagged by the system it is handled in the else statment manually  
void die(const char *message){
  if (errno){
    perror(message);
  }else if{
    printf("\nERROR: %s\n", message)
  }
  exit(1);
}

//function to print an address record to STDOUT or consol by defualt
void addressPrint(struct Address *addr){
  printf("%d %s %s\n", );
}

//function that loads a previuoulsy used datat base in to memory for the user to edit
//Takes a conncetion pointer struct as a pass by refrence argument. this conncect struct fontains a file pointer and a datata base struct
//this function dynamically allocates memory to handle database edits
void loadDB(struct Connection *conn){
  //fread() function comes from the stdio.h header file in c.
  //it needs a buffer (passed by pointer for locaition), it needs a size of buffer, and count of objects to be read, 
  //then it need a file object to read from
  //Ulitmatly fread takes data from a file and reads it into memory. it is bounded by the buffer size and how many time to read that sized buffer
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file)
  
  //error handling for a failed loading event
  if(rc!=1){
    die("File read Error when attempting to load database into memory");
  }
}


//










