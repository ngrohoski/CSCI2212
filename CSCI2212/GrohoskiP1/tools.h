/* file: tools.h ------------------------------------------------------------- */
/* header file for the tools library.                                          */
/* --------------------------------------------------------------------------- */
/* Local definitions and portability code.                                     */
/* Please enter your own system, name, class, and printer stream name.         */
/* --------------------------------------------------------------------------- */
#ifndef CTOOLS
#define CTOOLS

#define NAME    "Nathan Grohoski"
#define CLASS   "CSCI 2212"
//#define PRN     "prn"

#include <stdio.h>      
#include <stdlib.h>     /* for malloc() and calloc()*/     
#include <math.h>        
#include <string.h>     /* for time_t, time() and ctime()*/   
#include <time.h>        
#include <ctype.h>      /* for isspace() and isdigit() */ 
#include <limits.h>     /* for INT_MAX */   
#include <float.h>      /* for DOUBLE_MAX, etc. */
#include <stdarg.h>     /* for functions with variable # of arguments */

#define PI  3.1415927                                          

typedef char* cstring;
typedef FILE* cstream;
typedef enum {false, true} bool;

/* -------------------------------------------------------------------------- */
/* Routine screen and process management.------------------------------------ */
/* -------------------------------------------------------------------------- */
void    banner( void );
void    hold( void );                                    
void    bye( void );                                    
int     fatal( cstring format, ... );

/* -------------------------------------------------------------------------- */
/* Time and date.  ---------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
void    when( char date[], char hour[] );
cstring  today( char date[] );
cstring  oclock( char hour[] );

#endif
