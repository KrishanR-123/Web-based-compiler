//this is for storing tokens that we scan

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//token field can be T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
enum {
  T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

//tokens are going to be stored in this structure
struct token {
  int token;
  int intvalue;
};
