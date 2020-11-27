#ifndef extern_
#define extern_ extern
#endif

extern_ int Line;			// Current line number
extern_ int Putback;			// Character put back by scanner
extern_ FILE *Infile;			// Input and output files
extern_ FILE *Outfile;
extern_ struct token Token;	
extern_ char Text[TEXTLEN + 1];		
