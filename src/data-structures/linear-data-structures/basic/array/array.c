/* Implementation of array using integers. Change data type as needed.

   This file defines a structure `Array` which holds:
     (1) a pointer to an integer array
     (2) the capacity of the array
     (3) the current size of the array

   The file includes functions to:
     - create an array
     - insert an element into the array
     - delete an element from the array
     - access an element in the array
     - update an element in the array
     - print the array
*/
#include <stdio.h>

typedef struct Array
{ int *arr; // pointer to array
  int capacity; // maximum capacity of array
  int current_size; // current size of array
} Array;

Array* create_array(int capacity)
{ Array* array = (Array*)malloc(sizeof(Array));
  array->capacity = capacity;
  array-current_size = 0;
  array->arr = (int*)malloc(array->capacity * sizeof(int));
  return array;
}

// return of 0 indicates failure, return of 1 indicates success.
int insert_element(Array* array, int element)
{ if (array->current_size == array->capacity)
  { printf("Array is full\n");
    return 0;
  }
  array->arr[array->current_size] = element;
  array->current_size++;
  return 1;
}

// return of 0 indicates failure, return of 1 indicates success.
int delete_element(Array* array, int index)
{ if (index < 0 || index >= array->current_size)
  { printf("Index out of bounds\n");
    return 0;
  }
  for (int i = index; i < array->current_size - 1; i++)
  { array->arr[i] = array->arr[i+1];
  }
  array->current_size--;
  return 1;
}

// note, return of -1 does not necessarily indicate failure. tweak depending
// on needs of implementation.
int access_element(Array* array, int index)
{ if (index < 0 || index >= array->current_size)
  { printf("Index out of bounds\n");
    return -1;
  }
  return array->arr[index];
}

// return of 0 indicates failure, return of 1 indicates success.
int update_element(Array* array, intindex, int new_value)
{ if (index < 0 || index >= array->current_size)
  { printf("Index out of bounds\n");
    return 0;
  }
  array->arr[index] = new_value;
  return 1;
}

void print_array(Array* array)
{ for (int i = 0; i < array->current_size; i++)
  { printf("%d ", array->arr[i]);
  }
  printf("\n");
}

int main()
{ Array* array = create_array(5);
  insert_element(array, 10);
  insert_element(array, 20);
  insert_element(array, 30);
  print_array(array);
  delete_element(array, 1);
  print_array(array);
  printf("Element at index 1: %d\n", access_element(array, 1));
  print_array(array);
  return 0;
}
