#include "defs.h"
#include "data.h"
#include "decl.h"




// Return the position of character c in string s, or -1 if c not found
static int chrpos(char *s, int c) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}




// Get the next character from the input file.
static int next(void) {
  int c;

  if (Putback) {		// Use the character put
    c = Putback;		// back if there is one
    Putback = 0;
    return c;
  }

  c = fgetc(Infile);		// Read from input file
  if ('\n' == c)
    Line++;			// Increment line count
  return c;
}




// Put back an unwanted character
static void putback(int c) {
  Putback = c;
}




// Skip past input that we don't need to deal with, i.e. whitespace, newlines. Return the first character we do need to deal with.
static int skip(void) {
  int c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}




// Scan and return an integer literal value from the input file. Store the value as a string in Text.
static int scanint(int c) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", c)) >= 0) {
    val = val * 10 + k;
    c = next();
  }

  // We hit a non-integer character, put it back.
  putback(c);
  return val;
}





// It will scan and return the next token found in the input. Returning 1 if token valid, 0 if no tokens left.
int scan(struct token *t) {
  int c;

  // For skipping whitespace
  c = skip();

  // Determine the token based on input character
  switch (c) {
  case EOF: // EOF will return 0
    return (0);
  case '+': // + determined as T_PLUS  
    t->token = T_PLUS;
    break;
  case '-': // - determined as T_MINUS 
    t->token = T_MINUS;
    break;
  case '*': // * determined as T_STAR
    t->token = T_STAR;
    break;
  case '/': // / determined as T_SLASH
    t->token = T_SLASH;
    break;
  default:

    // If it's a digit, scan the literal integer value
    if (isdigit(c)) {
      t->intvalue = scanint(c);
      t->token = T_INTLIT;
      break;
    }
    
     // If not recognised by any of above mentioned
    printf("Unrecognised character %c on line %d\n", c, Line);
    exit(1);
  }

  // When a valid token
  return (1);
}
