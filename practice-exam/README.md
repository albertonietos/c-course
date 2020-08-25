# Practice exam

You can use the C reference for your support in implenting the tasks. Access to other network addresses have been blocked.

## 1. Implement following functions
Create a program that includes the following three functions, and a main function that tests their functionality.

* (a) `char *mystrcat(char *dest, const char *src)` that concatenates string src after string dst. The function does not allocate memory, but it assumes that the calling function arranges the memory somehow (as with the original strcat function). The function returns pointer to the beginnign of the string. In this task you must not use the strcat function that is defined in string.h header. (2p)

* (b) `unsigned int pickmax(unsigned int *numbers)`, that processes table numbers that contains unsigned integers. The table ends with number 0. The function should return the largest integer in the table. (2p)

* (c) `void set_bit(unsigned char *buffer, unsigned int n, int bit)`    , that goes through n bytes starting from address buffer, and sets bit number bit on in each of the bytes. The most significant bit is numbered 7, and the least significant bit is numbered 0. (2p)

* (d) `main` function that tests eachs of the above function by at least three different parameter combinations. (2p)

## 2. Fix program
The below functions do not work as specified. Fix functions such that they work as specified, and do not produce warnings or valgrind errors. The following three functions should be fixed:

* (a) function **strchr** that searches character c from string str and returns pointer to it. If the character cannot be found, the function return NULL. Function can also match the final nil character, i.e., if you give ‘\0’ as c, the function returns pointer to the end of the string. (2 p)

* (b) function **createArray** that dynamically allocates memory to store an integer array of size numbers, and initializes the array by increasing integers, starting from 0. The function returns pointer to the beginning of the array. You do not need to worry about releasing the memory: the calling function will take care of it. In this task you can assume that memory allocation always succeeds. (2 p)

* (c) function **addProduct** that adds a new item (of type struct products) at the end of dynamically allocated array, and initializes the item as indicated in arguments newtitle and newprice. The earlier length of the table is indicated by argument length. Function returns pointer to the beginning of the extended array. You can assume that memory allocation always succeeds. (2 p)

* (d) Implement `main` function that tests the other functions by at least two different parameter combinations. (2 p)

## 3. Program
Design a registeration system for an imaginary course. The system lists the names and student numbers of the participating students. You should use and extend the following given data structures in your program:

The *Course* structure lists a number of *Student* stuctures in some way, but you can decide yourself how. The implementation could be, for example, a linked list or dynamically allocated array. Complete the structures by adding missing fields, but the given fileds in *Student* structure must not be modified.

Implement the following functions:

* (a) `void add_student(Course *c, const char *name, const char *ID)`, that adds student by name name and student number ID to the student database that is indicated by Course structure c.

* (b) `void remove_student(Course *c, const char *ID)`, that removes the given student (ID) from Student list c. You can assume that an ID is stored in the list at most once.

The implementation must not use more memory that needed for the current student list. On the other hand, it must be able to store also large amounts of students. In other words, you will need to apply dynamic memory management in some way. You can assume that memory allocations always succeed.

You will get two points for succesful definition of data structures, and two points for each of the functions. Implement your own main function that tests both functions with at least three different inputs. Succesful main function will grant you two points. Altogether there are eight points in this task.

