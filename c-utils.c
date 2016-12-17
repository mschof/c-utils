////////////////////////////////////////////////////////////////////////////////
// File: C_utils.c                                                            //
// This file contains useful functions for C programming.                     //
// Notes:                                                                     //
// -                                                                          //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// --- Functions ---                                                          //
// Test* createNode()                                                         //
// void addNode(Test* root, Test* node)                                       //
// int getLinkedListIndex(Test* root, int value)                              //
// Test* swapNodeWithNext(Test* root, Test* node)                             //
// Test* sortLinkedList(Test* root)                                           //
// void freeLinkedList(Test* root)                                            //
// int* newIntArray(int size)                                                 //
// int* newIntArraySize(int* array, int size)                                 //
// void sortIntArray(int* array, int size)                                    //
// void printIntArray(int* array, int size)                                   //
// int** newXYIntArray(int x, int y)                                          //
// void fillXYIntArray(int** array, int x, int y)                             //
// void printXYIntArray(int** array, int x, int y)                            //
// void freeXYIntArray(int** array, int x)                                    //
// char* newCharArray(int size)                                               //
// char* newCharArraySize(char* array, int size)                              //
// void sortCharArray(char* array, int size)                                  //
// void printCharArray(char* array, int size)                                 //
// int strLength(char* string)                                                //
// void strRemoveChar(char* string, char remove)                              //
// void strReplaceChar(char* string, char old_char, char new_char)            //
// void strUpper(char* string)                                                //
// void strLower(char* string)                                                //
// void strInvertCase(char* string)                                           //
// char** strExplode(char* string, char delimiter)                            //
// void strArrayPrint(char** array, int size)                                 //
// void strArrayFree(char** array, int size)                                  //
// int strDistance(char* string_1, char* string_2)                            //
// double mathPower(double input, int power)                                  //
// unsigned long long mathFaculty(int input)                                  //
// int mathMod(int a, int b)                                                  //
// long int getFileSize(char* file_path)                                      //
// void writeFileBinary(char* buffer, char* file_path)                        //
// char* readFileBinary(char* file_path)                                      //
// int deleteFile(char* file_path)                                            //
// int main(int argc, char** argv)                                            //
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
// Including libraries.
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------

// Used for strDistance function
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) :\
  ((b) < (c) ? (b) : (c)))

//------------------------------------------------------------------------------
// Providing a struct for testing
//------------------------------------------------------------------------------
typedef struct Test
{
  int value;
  struct Test* next;
} Test;

// ----------------------------
// STRUCT FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// Test* createNode()
// Creates a new object from type "Test" and allocates memory for it.
// @return Test* New object, if memory is available. Null, otherwise.
//------------------------------------------------------------------------------
Test* createNode()
{
  Test* object = (Test*)malloc(sizeof(Test));
  if(!object)
    printf("Out of memory!\n");
  return object;
}

//------------------------------------------------------------------------------
// void addNode(Test* root, Test* node)
// Adds a new object to a linked list.
// @param Test* The root of the linked list.
// @param Test* Node, which has to be added.
//------------------------------------------------------------------------------
void addNode(Test* root, Test* node)
{
  if(root->next == NULL)
  {
    root->next = node;
    node->next = NULL;
  }
  else
  {
    while(root->next != NULL)
    {
      root = root->next;
    }
    root->next = node;
    node->next = NULL;
  }
}

//------------------------------------------------------------------------------
// int getLinkedListIndex(Test* root, int value)
// Gets index of the first element with a certain value.
// @param Test* Root of the list.
// @return int Index of the element. -1 if not found.
//------------------------------------------------------------------------------
int getLinkedListIndex(Test* root, int value)
{
  int index = 0;
  Test* tmp = root;
  while(tmp)
  {
    if(tmp->value == value)
      return index;
    tmp = tmp->next;
    index++;
  }
  
  return -1;
}

//------------------------------------------------------------------------------
// Test* swapNodeWithNext(Test* root, Test* node)
// Swaps a node in a linked list with its next one.
// @param Test* Root of the list.
// @param Test* Node pointer to swap with the next one.
// @return Test* New pointer to the root of the list.
//------------------------------------------------------------------------------
Test* swapNodeWithNext(Test* root, Test* node)
{
  Test* new_root = root;
  Test* n_tmp = root;
  
  if(node == root)
  {
    new_root = root->next; 
    Test* tmp = n_tmp;
    n_tmp = n_tmp->next;
    tmp->next = n_tmp->next;
    n_tmp->next = tmp;
  }
  else
  {
    while(root && root->next)
    {
      if(root->next == node)
      {
        Test* a = root;
        Test* b = node;
        Test* c = node->next;
      
        a->next = c;
        b->next = c->next;
        c->next = b;
        
        return new_root;
      }
      root = root->next;
    }
  }
  
  return new_root;
}

//------------------------------------------------------------------------------
// Test* sortLinkedList(Test* root)
// Sorts a linked list in ascending order according to a specific value by
// swapping pointers.
// @param Test* Root of the linked list.
// @return Test* New pointer to the first element of the sorted list.
//------------------------------------------------------------------------------
Test* sortLinkedList(Test* root)
{
  Test* new_root = root;
  int done = 0;
  
  while(done == 0)
  {
    done = 1;
    root = new_root;
    while(root->next)
    {
      if(root->value > root->next->value)
      {
        new_root = swapNodeWithNext(new_root, root);
        done = 0;
      }
      else
        root = root->next;
    }
  }
  
  return new_root;
}

//------------------------------------------------------------------------------
// void freeLinkedList(Test* root)
// Frees all the objects of a linked list.
// @param Test* Root of the linked list.
//------------------------------------------------------------------------------
void freeLinkedList(Test* root)
{
  Test* node;
  Test* next;
  for(node = root; node != NULL; node = next)
  {
    next = node->next;
    free(node);
  }
}

// ----------------------------
// INT FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// int* newIntArray(int size)
// Create a new int array with the given size and allocates memory for it.
// @param int Size of the new int array.
// @return int* The new int array. Null if no memory is available.
//------------------------------------------------------------------------------
int* newIntArray(int size)
{
  int* array;
  array = malloc(size * sizeof(int));
  if(!array)
    printf("Out of memory!\n");
  return array;
}

//------------------------------------------------------------------------------
// int* newIntArraySize(int* array, int size)
// Reallocates memory for a given int array.
// @param int* Int array to update.
// @param int New size of the int array.
// @return int* The new int array. Null if no memory is available.
//------------------------------------------------------------------------------
int* newIntArraySize(int* array, int size)
{
  array = realloc(array, size * sizeof(int));
  if (!array)
    printf("Out of memory!\n");
  return array;
}

//------------------------------------------------------------------------------
// void sortIntArray(int* array, int size)
// Sorts an int array with the given size in ascending order.
// @param int* Int array to sort.
// @param int Size of the updated int array.
//------------------------------------------------------------------------------
void sortIntArray(int* array, int size)
{
  if(size > 1)
  {
    int minimum_index = array[0];
    int outer_counter = 0;
    int inner_counter = 0;
    int temp = 0;
    while(outer_counter < size)
    {
      inner_counter = outer_counter;
      minimum_index = outer_counter;
      while(inner_counter < size)
      {
        if(array[inner_counter] < array[outer_counter])
          minimum_index = inner_counter;
        inner_counter++;
      }
      temp = array[minimum_index];
      array[minimum_index] = array[outer_counter];
      array[outer_counter] = temp;
      outer_counter++;
    }
  }
}

//------------------------------------------------------------------------------
// void printIntArray(int* array, int size)
// Prints all integers in a given int array.
// @param int* Int array to print.
// @param int Size of the int array.
//------------------------------------------------------------------------------
void printIntArray(int* array, int size)
{
  int counter = 0;
  for(; counter < size; counter++)
    printf("%d\n", array[counter]);
}

//------------------------------------------------------------------------------
// int** newXYIntArray(int x, int y)
// Creates a new two-dimensional int array and allocates memory for it.
// @param int Widht (x) of the new int array.
// @param int Height (y) of the new int array.
// @return int** The new int array. Null if no memory is available.
//------------------------------------------------------------------------------
int** newXYIntArray(int x, int y)
{
  int counter = 0;

  int** array = (int**)malloc(x * sizeof(int*));
  if(!array)
    printf("Out of memory!\n");
    
  for(; counter < y; counter++)
  {
    array[counter] = (int*)malloc(y * sizeof(int));
    if(!array[counter])
      printf("Out of memory!\n");
  }
  
  return array;
}

//------------------------------------------------------------------------------
// void fillXYIntArray(int** array, int x, int y)
// Fills a two-dimensional int array with content (integers from 0 - n).
// @param int** Int array to fill.
// @param int Widht (x) of the int array.
// @param int Height (y) of the int array.
//------------------------------------------------------------------------------
void fillXYIntArray(int** array, int x, int y)
{
  int x_counter = 0;
  int y_counter = 0;
  int num_counter = 0;
  
  for(; x_counter < x; x_counter++)
  {
    for(y_counter = 0; y_counter < y; y_counter++)
    {
      array[x_counter][y_counter] = num_counter;
      num_counter++;
    }
  }
}

//------------------------------------------------------------------------------
// void printXYIntArray(int** array, int x, int y)
// Prints content of a two-dimensional int array.
// @param int** Int array to print.
// @param int Widht (x) of the int array.
// @param int Height (y) of the int array.
//------------------------------------------------------------------------------
void printXYIntArray(int** array, int x, int y)
{
  int x_counter = 0;
  int y_counter = 0;
  
  for(; x_counter < x; x_counter++)
  {
    for(y_counter = 0; y_counter < y; y_counter++)
    {
      printf("%d", array[x_counter][y_counter]);
    }
    printf("\n");
  }
}

//------------------------------------------------------------------------------
// void freeXYIntArray(int** array, int x)
// Frees a whole two-dimensional int array.
// @param int** Int array to free.
// @param int Height (x) of the int array.
//------------------------------------------------------------------------------
void freeXYIntArray(int** array, int x)
{
  int counter = 0;
  for(; counter < x; counter++)
    free(array[counter]);
  free(array);
}

// ----------------------------
// CHAR FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// char* newCharArray(int size)
// Creates a new char array and allocates memory for it.
// @param int Size of the array.
// @return char* The new char array. Null if no memory is available.
//------------------------------------------------------------------------------
char* newCharArray(int size)
{
  char* array;
  array = malloc(size * sizeof(char));
  if(!array)
    printf("Out of memory!\n");
  return array;
}

//------------------------------------------------------------------------------
// char* newCharArraySize(char* array, int size)
// Reallocates memory for a given char array.
// @param char* Char array to update.
// @param int New size of the char array.
// @return char* The new char array. Null if no memory is available.
//------------------------------------------------------------------------------
char* newCharArraySize(char* array, int size)
{
  array = realloc(array, size * sizeof(char));
  if (!array)
    printf("Out of memory!\n");
  return array;
}

//------------------------------------------------------------------------------
// void sortCharArray(char* array, int size)
// Sorts a char array in alphabetic order.
// @param char* Char array to sort.
// @param int Size of the char array.
//------------------------------------------------------------------------------
void sortCharArray(char* array, int size)
{
  if(size > 1)
  {
    int minimum_index = array[0];
    int outer_counter = 0;
    int inner_counter = 0;
    int temp = 0;
    while(outer_counter < size)
    {
      inner_counter = outer_counter;
      minimum_index = outer_counter;
      while(inner_counter < size)
      {
        if(array[inner_counter] < array[outer_counter])
          minimum_index = inner_counter;
        inner_counter++;
      }
      temp = array[minimum_index];
      array[minimum_index] = array[outer_counter];
      array[outer_counter] = temp;
      outer_counter++;
    }
  }
}

//------------------------------------------------------------------------------
// void printCharArray(char* array, int size)
// Prints content of a given char array.
// @param char* Char array to print.
// @param int Size of the char array.
//------------------------------------------------------------------------------
void printCharArray(char* array, int size)
{
  int counter = 0;
  for(; counter < size; counter++)
    printf("%c\n", array[counter]);
}

// ----------------------------
// CSTRING FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// int strLength(char* string)
// Determines the length of a CString (without '\0').
// @param char* CString to check.
// @return int Length of the given CString.
//------------------------------------------------------------------------------
int strLength(char* string)
{
  char* temp = string;
  int len = 0;
  
  while(*temp++)
    len++;
    
  return len;
}

//------------------------------------------------------------------------------
// void strRemoveChar(char* string, char remove)
// Removes all instances of a given char from the given CString.
// @param char* CString to edit.
// @param char Character to remove.
//------------------------------------------------------------------------------
void strRemoveChar(char* string, char remove)
{
  int len = strLength(string);
  int outer_counter = 0;
  int inner_counter = 0;
  
  for(; outer_counter < len; outer_counter++)
  {
    if(string[outer_counter] == remove)
    {
      inner_counter = outer_counter;
      for(; inner_counter < len; inner_counter++)
      {
        string[inner_counter] = string[inner_counter + 1];
      }
    }
  }
}

//------------------------------------------------------------------------------
// void strReplaceChar(char* string, char old_char, char new_char)
// Replaces all instances of a given char with another one.
// @param char* CString to edit.
// @param char Old char.
// @param char New char.
//------------------------------------------------------------------------------
void strReplaceChar(char* string, char old_char, char new_char)
{
  int len = strLength(string);
  int counter = 0;
  
  for(; counter < len; counter++)
  {
    if(string[counter] == old_char)
      string[counter] = new_char;
  }
}

//------------------------------------------------------------------------------
// void strUpper(char* string)
// Makes a given CString uppercase.
// @param char* CString to edit.
//------------------------------------------------------------------------------
void strUpper(char* string)
{
  int len = strLength(string);
  int counter = 0;
  
  for(; counter < len; counter++)
  {
    if(string[counter] >= 97 && string[counter] <= 122)
    {
      string[counter] = string[counter] - 32;
    }
  }
}

//------------------------------------------------------------------------------
// void strLower(char* string)
// Makes a given CString lowercase.
// @param char* CString to edit.
//------------------------------------------------------------------------------
void strLower(char* string)
{
  int len = strLength(string);
  int counter = 0;
  
  for(; counter < len; counter++)
  {
    if(string[counter] >= 65 && string[counter] <= 90)
    {
      string[counter] = string[counter] + 32;
    }
  }
}

//------------------------------------------------------------------------------
// void strInvertCase(char* string)
// Inverts the case of every char inside a given CString.
// @param char* CString to check.
//------------------------------------------------------------------------------
void strInvertCase(char* string)
{
  int len = strLength(string);
  int counter = 0;
  
  for(; counter < len; counter++)
  {
    if(string[counter] >= 97 && string[counter] <= 122)
    {
      string[counter] = string[counter] - 32;
    }
    else if(string[counter] >= 65 && string[counter] <= 90)
    {
      string[counter] = string[counter] + 32;
    }
  }
}

//------------------------------------------------------------------------------
// char** strExplode(char* string, char delimiter)
// Splits a CString into different tokens according to the delimiter.
// @param char* CString to split.
// @param char Delimiter to use.
// @return char** CString array containing all the tokens.
//------------------------------------------------------------------------------
char** strExplode(char* string, char delimiter)
{
  int size = strLength(string);
  int token_count = 1;
  int counter = 0;
  int token_counter = 0;
  int char_counter = 0;
  int inner_counter = 0;
  
  int max_chars = 0;
  int current_chars = 0;
  
  for(; counter < size; counter++)
  {
    current_chars++;
    if(string[counter] == delimiter)
    {
      token_count++;
      if(current_chars > max_chars)
      {
        max_chars = current_chars;
      }
      current_chars = 0;
    }
  }
  
  char** array = (char**)malloc(token_count * sizeof(char*));
  
  if(!array)
    printf("Out of memory!\n");
    
  for(counter = 0; counter <= size; counter++)
  {
    inner_counter++;
    if(string[counter] == delimiter || counter == size)
    {
      array[token_counter] =
        (char*)malloc((inner_counter + 1) * sizeof(char));
      if(!array[token_counter])
        printf("Out of memory!\n");
      inner_counter = 0;
      token_counter++;
    }
  }
  
  inner_counter = 0;
  token_counter = 0;
  for(counter = 0; counter <= size; counter++)
  {
    if(string[counter] == delimiter || counter == size)
    {
      char_counter = 0;
      for(; inner_counter <= counter; inner_counter++)
      {
        if(inner_counter != counter)
          array[token_counter][char_counter] = string[inner_counter];
        else
          array[token_counter][char_counter] = '\0';
        char_counter++;
      }
      token_counter++;
    }
  }

  return array;
}

//------------------------------------------------------------------------------
// void strArrayPrint(char** array, int size)
// Prints all CStrings inside a CString array.
// @param char** CString array to print.
// @param int Size of the CString array.
//------------------------------------------------------------------------------
void strArrayPrint(char** array, int size)
{
  int counter = 0;
  for(; counter < size; counter++)
    printf("%s\n", array[counter]);
}

//------------------------------------------------------------------------------
// void strArrayFree(char** array, int size)
// Frees a whole CString array.
// @param char** CString array to free.
// @param int Size of the CString array.
//------------------------------------------------------------------------------
void strArrayFree(char** array, int size)
{
  int counter = 0;
  for(; counter < size; counter++)
    free(array[counter]);
  free(array);
}

//------------------------------------------------------------------------------
// int strDistance(char* string_1, char* string_2)
// Returns the "Levenshtein distance" between two CStrings.
// @param char* First string.
// @param char* Second string.
// @return int The distance between the strings.
//------------------------------------------------------------------------------
int strDistance(char* string_1, char* string_2)
{
  int x, y, distance;
  int string_1_len = strLength(string_1);
  int string_2_len = strLength(string_2);
  int matrix[string_2_len + 1][string_1_len + 1];
  matrix[0][0] = 0;
  
  for(x = 1; x <= string_2_len; x++)
    matrix[x][0] = matrix[x - 1][0] + 1;
  for(y = 1; y <= string_1_len; y++)
    matrix[0][y] = matrix[0][y - 1] + 1;
  for(x = 1; x <= string_2_len; x++)
    for(y = 1; y <= string_1_len; y++)
      matrix[x][y] = MIN3(matrix[x - 1][y] + 1, matrix[x][y - 1] + 1,
        matrix[x - 1][y - 1] + (string_1[y - 1] == string_2[x - 1] ? 0 : 1));

  distance = matrix[string_2_len][string_1_len];
  return distance;
}

// ----------------------------
// MATH FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// double mathPower(double input, int power)
// Calculates input^power.
// @param double Input number.
// @param int Power.
// @return double Result.
//------------------------------------------------------------------------------
double mathPower(double input, int power)
{
  double result = 1;
  int power_counter = power;
  
  if(power == 0)
   return result;
  
  while(power_counter)
  {
    result *= input;
    power_counter > 0 ? power_counter-- : power_counter++;
  }
  
  if(power > 0)
    return result;
  else
    return (1 / result);
}

//------------------------------------------------------------------------------
// unsigned long long mathFaculty(int input)
// Calculates the faculty of the input.
// @param int Input number.
// @return unsigned long long Result.
//------------------------------------------------------------------------------
unsigned long long mathFaculty(int input)
{
  unsigned long long result = 1;

  while(input)
  {
    result *= input;
    input--;
  }

  return result;
}

//------------------------------------------------------------------------------
// int mathMod(int a, int b)
// Calculates a mod b.
// @param a Input number.
// @param b Input number.
// @return int Result.
//------------------------------------------------------------------------------
int mathMod(int a, int b)
{
  int result = a;
  
  while(result >= b)
    result = result - b;
  
  return result;
}

// ----------------------------
// FILE I/O FUNCTIONS
// ----------------------------

//------------------------------------------------------------------------------
// long int getFileSize(char* file_path)
// Returns size of a file in bytes (max 2147483647 bytes, which is ~2GB).
// @param char* Path to the file.
// @return long int File size in bytes, -1 if error occured.
//------------------------------------------------------------------------------
long int getFileSize(char* file_path)
{
  long int file_size;
  
	FILE* file = fopen(file_path, "rb");
	if(!file)
		return -1;
	
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
  
  fclose(file);
  
  return file_size;
}

//------------------------------------------------------------------------------
// void writeFileBinary(char* buffer, char* file_path)
// Writes buffer content into a file.
// @param char* Content to write.
// @param char* Path to the file.
//------------------------------------------------------------------------------
void writeFileBinary(char* buffer, char* file_path)
{
  FILE* file;
  
  file = fopen(file_path, "wb");
  if(!file)
	{
		printf("Unable to open file %s!\n", file_path);
    return;
	}
  
  fwrite(buffer, strLength(buffer), 1, file);
  
  fclose(file);
}

//------------------------------------------------------------------------------
// char* readFileBinary(char* file_path)
// Reads a file and returns content in a char*.
// @param char* Path to the file.
// @return char* Content of the file, NULL if error occured.
//------------------------------------------------------------------------------
char* readFileBinary(char* file_path)
{
	FILE* file;
	char* buffer;
	long int file_length = getFileSize(file_path);

	file = fopen(file_path, "rb");
	if(!file || file_length == -1)
	{
		printf("Unable to open file %s!\n", file_path);
		return NULL;
	}
	
	fseek(file, 0, SEEK_SET);

	buffer = (char*)calloc((file_length + 1), sizeof(char));
	if(!buffer)
	{
    printf("Out of memory!\n");
    fclose(file);
    return NULL;
	}

	fread(buffer, file_length, 1, file);
  
	fclose(file);
  
	return buffer;
}

//------------------------------------------------------------------------------
// int deleteFile(char* file_path)
// Deletes a file.
// @param char* Path to the file.
// @return int Returns success, 0 if no errors occured.
//------------------------------------------------------------------------------
int deleteFile(char* file_path)
{
  return remove(file_path);
}

// ----------------------------
// MAIN FUNCTION
// ----------------------------

//------------------------------------------------------------------------------
// int main(int argc, char** argv)
// Main function, testing all functions above.
// @param int Parameter count.
// @param char** CString array of parameters.
// @return int Success.
//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  // ----------------------------
  // STRUCT TESTING
  // ----------------------------
  
  printf("--- STRUCT TESTING ---\n");
  
  // Creation
  Test* root = createNode();
  Test* node_1 = createNode();
  Test* node_2 = createNode();
  
  // Assigning values
  root->value = 3;
  node_1->value = 2;
  node_2->value = 1;
  
  // Setting initial next
  root->next = NULL;
  
  // Adding nodes
  addNode(root, node_1);
  addNode(root, node_2);
  
  // Print unsorted list
  printf("Unsorted list:\n");
  printf("%d\n", root->value);
  printf("%d\n", root->next->value);
  printf("%d\n", root->next->next->value);
  
  // Getting valid index of element (search for value 2)
  printf("Index of valid element with value 2: %d\n",
    getLinkedListIndex(root, 2));
  
  // Getting invalid index of element (search for value 0)
  printf("Index of invalid element with value 0: %d\n",
    getLinkedListIndex(root, 0));
  
  // Sort linked list according to value
  root = sortLinkedList(root);
  
  // Print sorted list
  printf("Sorted list:\n");
  printf("%d\n", root->value);
  printf("%d\n", root->next->value);
  printf("%d\n", root->next->next->value);
  
  // Free memory
  freeLinkedList(root);
  
  // ----------------------------
  // INT TESTING
  // ----------------------------
  
  printf("--- INT TESTING ---\n");
  
  // Create int array
  int* int_array = newIntArray(2);
  
  // Add values
  int_array[0] = 4;
  int_array[1] = 3;
  
  // Reallocate memory for new size
  int_array = newIntArraySize(int_array, 4);
  
  // Add new values
  int_array[2] = 2;
  int_array[3] = 1;
  
  // Sort array (4 = int count)
  sortIntArray(int_array, 4);
  
  // Print array values (4 = int count)
  printIntArray(int_array, 4);
  
  // Free memory
  free(int_array);
  
  // Create 2d int array
  int** xy_int_array = newXYIntArray(5, 5);
  
  // Fill 2d int array with content
  fillXYIntArray(xy_int_array, 5, 5);
  
  // Print content of 2d int array
  printXYIntArray(xy_int_array, 5, 5);
  
  // Free two-dimensional int array (5 = x size)
  freeXYIntArray(xy_int_array, 5);
  
  // ----------------------------
  // CHAR TESTING
  // ----------------------------
  
  printf("--- CHAR TESTING ---\n");
  
  // Initialize char array
  char* char_array = newCharArray(2);
  
  // Add chars
  char_array[0] = 'd';
  char_array[1] = 'c';
  
  // Reallocate memory for new size
  char_array = newCharArraySize(char_array, 4);
  
  // Add new chars
  char_array[2] = 'b';
  char_array[3] = 'a';
  
  // Sort array (4 = char count)
  sortCharArray(char_array, 4);
  
  // Print array values (4 = char count)
  printCharArray(char_array, 4);
  
  // Free memory
  free(char_array);
  
  // ----------------------------
  // CSTRING TESTING
  // ----------------------------
  
  printf("--- CSTRING TESTING ---\n");
  
  char string[] = "-hE1-1O wOR-1D!-";
  
  // Invert case
  strInvertCase(string);
  
  // Remove chars
  strRemoveChar(string, '-');
  
  // Replace chars
  strReplaceChar(string, '1', 'l');
  
  // Print final string
  printf("%s\n", string);
  
  // Create long string containing different tokens
  char* tokens = "Hello, my lovely world!";
  
  // Split this string into a string array with tokens
  char** string_array = strExplode(tokens, ' ');
  
  // Print strings inside a string array (4 = token count)
  strArrayPrint(string_array, 4);
  
  // Free a CString array (4 = token count)
  strArrayFree(string_array, 4);
  
  // Levenshtein distance
  char* string_1 = "Work";
  char* string_2 = "Wall";
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n",
    string_1, string_2, strDistance(string_1, string_2));

  // ----------------------------
  // MATH TESTING
  // ----------------------------
  
  printf("--- MATH TESTING ---\n");

  // Power
  printf("2^10 = %lf\n", mathPower(2, 10));
  printf("16^(-2) = %lf\n", mathPower(16, -2));

  // Faculty
  printf("The faculty of 5 is %llu.\n", mathFaculty(5));
  printf("The faculty of 10 is %llu.\n", mathFaculty(10));
  
  // Modulo
  printf("13 mod 17 = %d\n", mathMod(13, 17));
  printf("3748 mod 27 = %d\n", mathMod(3748, 27));
  
  // ----------------------------
  // FILE I/O TESTING
  // ----------------------------
  
  printf("--- FILE I/O TESTING ---\n");
  
  char* file_path = "file.bin";
  
  // Write file
  char* buffer_write = "This is a test.";
  writeFileBinary(buffer_write, file_path);
  printf("File \"%s\" written!\n", file_path);

  // Read written file
  char* buffer_read = readFileBinary(file_path);
  if(buffer_read)
  {
    // Print that reading was successful
    printf("Successfully read from file \"%s\"!\n", file_path);
    // Print file size
    printf("File size: %li bytes\n", getFileSize(file_path));
    // Print file content
    printf("File content: %s\n", buffer_read);
    // Free buffer
    free(buffer_read);
  }
  
  // Delete file
  if(deleteFile(file_path) != 0)
    printf("Error deleting file \"%s\"!\n", file_path);
  else
    printf("File \"%s\" successfully deleted!\n", file_path);

  return 0;
}
