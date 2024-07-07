#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

//Defines the components of an address object, will be used a a record in the database
struct Address {
    int id;
    int set; //
    char name[MAX_DATA];
    char email[MAX_DATA];
};

//Struct that defines the components of a database. capable of holding 100 records of the address object
struct Database {
    struct Address rows[MAX_ROWS];
};

//Structure containing database and storage medium , in this case a file
struct Connection {
    FILE *p_file;
    struct Database *p_db;
};


//BEGIN FUNCTIONS LISTS

//function is called when a error is identified. prints error mesage to STDERR using a function from the errno.h header file
//if the error is not compatible with errno.h or is not flagged by the system it is handled in the else statment manually  
void die(const char *p_message) {
    if (errno) {
        perror(p_message);
    }
    else {
        printf("\nERROR: %s\n", p_message);
    }
    exit(1);
}

//function to print an address record to STDOUT or consol by defualt
void printAddr(struct Address *p_addr) {
    printf("%d %s %s\n", p_addr->id, p_addr->name, p_addr->email);
}

//function that loads a previuoulsy used datat base in to memory for the user to edit
//Takes a conncetion pointer struct as a pass by refrence argument. this conncect struct fontains a file pointer and a datata base struct
//this function dynamically allocates memory to handle database edits
void loadDB(struct Connection *p_conn) {
    //fread() function comes from the stdio.h header file in c.
    //it needs a buffer (passed by pointer for locaition), it needs a size of buffer, and count of objects to be read, 
    //then it need a file object to read from
    //Ulitmatly fread takes data from a file and reads it into memory. it is bounded by the buffer size and how many time to read that sized buffer
    int rc = fread(&p_conn->p_db, sizeof(struct Database), 1, p_conn->p_file);

    //error handling for a failed loading event
    if (rc != 1) {
        die("File read Error when attempting to load database into memory");
    }
}


//Function that opens the database, takes a pointer to the file string to finde a file in storage. mallocs a a buffer on the heap to fit the database.
//once the heap is configured for the database it will read the file into heap memory
//ultimatly builds and returns a connection struc
//this connection servesas the intetrface tho the db once its loaded into memory
struct Connection *openDatabase(const char *p_filename, char mode) {

    //allocate heap memory that will fit a conncetion structure, recive trhe pointer back and apply it to a connection var / obj
    struct Connection *p_conn = malloc(sizeof(struct Connection));
    if (!p_conn) {
        die("memoray allcation error for the connection struct");
    }

    //allocate memore on the heap for the databes inside of the connection, assign pointer locations
    p_conn->p_db = malloc(sizeof(struct Database));
    if (!p_conn->p_db) {
        die("memoray allcation error for the database struct");
    }

    //open file as a read or write depending on user args
    //if user opens wiyth read function the load database from file into memory via connection
    if (mode == 'c') {
        p_conn->p_file = fopen(p_filename, "w");

    }
    else {
        p_conn->p_file = fopen(p_filename, "r+");

        //if file stream is valid then laod db via connection
        if (p_conn->p_file) {
            loadDb(p_conn);
        }
    }
    if (!p_conn->p_file) {
        die("failed to open file");
    }
    return p_conn;
}

//Function for cleaning creaing the heap memory cand destroying thre conn struct with subcomponents
void closeDatabase(struct Connection *p_conn) {
    if (p_conn) {
        if (p_conn->p_file) {
            fclose(p_conn->p_file);
        }
        if (p_conn->p_db) {
            free(p_conn->p_db);
        }
        free(p_conn);
    }
}

//function for writing new data to the database
void writeDatabase(struct Connection * p_conn) {
    //std lib function taking a file stream as a arg
    rewind(p_conn->p_file);
    //fwrite is a stlib for writing to a file stream from a buffer of defined size
    //returns the number of "items" of size that it sucessfuly writes to teh file
    int rc = fwrite(p_conn-> p_db, sizeof(struct Database), 1, p_conn->p_file);
    if (rc != 1) {
        die("failed to write Database");
    }

    //std lib function that "flushes" a stream if open in write mode
    //essentially it writes the buffer to file adn discards buffer
    rc = fflush(p_conn->p_file);
    if (rc == -1) {
        die("Cannot flush Database");
    }
}


//inital;ize  the database records by buoilding a init version inn the stact 
// and then using the refrence to the conn (located on the heap) to store 
// each record in its location in the adatabse row/record
void createDatabase(struct Connection * p_conn) {

    for (int i = 0; i < MAX_ROWS; i++) {
        // initialize a single prototype address (or database row/record)
        struct Address addr = { .id = i, .set = 0 };
        //assigne this record to the db ar the appropriate spot
        p_conn->p_db->rows[i] = addr;
    }
}


//Function that moves user data into the database
//takes user data in form of name a dn email and id
//findes the record and sets it to full and copys data over
void setDatabase(struct Connection *p_conn, int id, const char *p_name, const char * p_email) {

    //get point to an addr from the conn struct
    struct Address *p_addr = &p_conn->p_db->rows[id];
    //checks addr is already occupied
    if (p_addr->set) {
        die("address alread set, Deleate it first");
    }

    p_addr->set = 1;
    //BUG (MAX_Data to mush? overflow the memory space
    char* res = strncpy(p_addr->name, p_name, MAX_DATA);

    if (!res) {
        die("Name copy failed");
    }

    res = strncpy(p_addr->email, p_email, MAX_DATA);

    if (!res) {
        die("Name copy failed");
    }
}

//retirev an record for a given record ID
void getDatabase(struct Connection *p_conn, int id) {
    //get addr location from conn and store it in a temp pointer
    struct Address* p_addr = &p_conn->p_db->rows[id];

    if (p_addr->set){
        printAddr(p_addr);
    }else {
        die("ID is not set");
    }

}

//deletes datasbase record
void deleteDatabase(struct Connection * p_conn, int id) {
     //get addr location from conn and store it in a temp pointer
    struct Address addr = { .id = id, .set = 0 };
    //overwrite the record at the ID given by parmeter/arg as a zeroed 
    p_conn->p_db->rows[id] = addr;
}

//prints the database fully to console
void listDatabase(struct Connection * p_conn) {
    struct Database *p_db = p_conn->p_db;

    //for loop to iterate through each record
    for (int i = 0; i < MAX_ROWS; i++) {
        //set record to point IOT refrence
        struct Address *p_cur = &p_db->rows[i];

        if (p_cur->set) {
            printAddr(p_cur);
        }
    }
}



int main(int argc, char* argv[]) {

    if (argc < 3) {
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }

    char* p_filename = argv[1];
    char action = argv[2][0];
    struct Connection* p_conn = openDatabase(p_filename, action);
    int id = 0;

    if (argc > 3) id = atoi(argv[3]);

    if (id >= MAX_ROWS) die("Not enough space.");

    switch (action) {
    case 'c':
        createDatabase(p_conn);
        databseWrite(p_conn);
        break;

    case 'g':
        if (argc != 4) die("Need idto get");
        getDatabase(p_conn, id);

    case 's':
        if (argc != 6) die("Need id, name, email to set");
        setDatabase(p_conn, id, argv[4], argv[5]);
        writeDatabase(p_conn);
        break;

    case 'd':
        if (argc != 4) die("need id to delet");

        deleteDatabse(p_conn, id);
        writeDatabse(p_conn);
        break;

    case 'l':
        listDatabse(p_conn);
        break;

    default:
        die("Invalide actionc: create, g=get, s=set, d=del, l=list");

    }
    closeDatabase(p_conn);


    return 0;

}
