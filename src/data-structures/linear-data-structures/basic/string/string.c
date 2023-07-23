#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100

typedef struct
{ char* data;
  int length;
} String;

// Initialize a new String object
void init_string(String* string, const char* data)
{ if (data == NULL)
  { printf("Error: NULL data cannot be used to initialize a string\n");
    return;
  }
  int i = 0;
  while (data[i] != '\0')
  { i++;
    if(i >= MAX_STRING_SIZE)
    { printf("Error: Data length exceeds maximum string size\n");
      return;
    }
  }
  string->length = i;
  string->data = (char*)malloc((string->length+1) * sizeof(char));

  if (string->data == NULL)
  { printf("Error: Memory allocation failed\n");
    return;
  }
  for (i = 0; i < string->length; i++)
  { string->data[i] = data[i];
  }
  string->data[i] = '\0';
}

// Free the memory allocated for the String object
void free_string(String* string)
{ free(string->data);
  string->data = NULL;
  string->length = 0;
}

// Display the string
void display_string(const String* string)
{ printf("%s\n", string->data);
}

// Concatenate string2 to the end of string1
void concatenate(String* string1, const String* string2)
{ if (string1->length + string2->length >= MAX_STRING_SIZE)
  { printf("Error: Concatenation will exceed maximum string size\n");
    return;
  }
  string1->data = realloc(string1->data, string1->length + string2->length + 1);
  if (string1->data == NULL)
  { printf("Error: Memory allocation failed\n");
    return;
  }
  for (int i = 0; i < string2->length; i++)
  { string1->data[string1->length + i] = string2->data[i];
  }
  string1->length += string2->length;
  string1->data[string1->length] = '\0';
}

// Function to convert a string to an integer
int string_to_int(const String* string, int* output)
{ int result = 0;
  for (int i = 0; i < string->length; i++)
  { if (string->data[i] < '0' || string->data[i] > '9')
    { printf("Error: Invalid integer\n");
      return -1;
    }
    result = result * 10 + (string->data[i] - '0');
  }
  *output = result;
  return 0;
}

// Function to convert a string to a float
int string_to_float(const String* string, float* output)
{ float result = 0.0f;
  int decimal_place = 0;
  for (int i = 0; i < string->length; i++)
  { if (string->data[i] == '.' && decimal_place == 0)
    { decimal_place = 1;
    }
    else if (string->data[i] < '0' || string->data[i] > '9')
    { printf("Error: Invalid float\n");
      return -1;
    }
    else
    { result = result * 10 + (string->data[i] - '0');
	    decimal_place *= 10;
    }
  }
  *output = result / decimal_place;
  return 0;
}

// Function to convert a string to a char
int string_to_char(const String* string, char* output)
{ if (string->length != 1)
  { printf("Error: Invalid character\n");
    return -1;
  }
  *output = string->data[0];
  return 0;
}

int main()
{ String string1, string2;
  init_string(&string1, "123");
  init_string(&string2, "123.45");
  int int_result = 0;
  float float_result = 0.0f;
  char char_result = '\0';
  if (string_to_int(&string1, &int_result) == 0)
  { printf("String to Int: %d\n", int_result);
  }
  if (string_to_float(&string2, &float_result) == 0)
  { printf("String to Float: %f\n", float_result);
  }
  if (string_to_char(&string1, &char_result) == 0)
  { printf("String to Char: %c\n", char_result);
  }
  free_string(&string1);
  free_string(&string2);
  return 0;
}
