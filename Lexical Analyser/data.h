//header line containing few global variables and file pointer
//replacing extern with extern_ so that main.c will remove extern_ and these variable will belong to main.c only

#ifndef extern_ //allows conditionl compilation
 #define extern_ extern //allows the definition of macros within your src
#endif

//Global Variables
extern_ int     Line;
extern_ int	Putback;
extern_ FILE	*Infile;
