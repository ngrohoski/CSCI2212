/* File: tools.c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  /
/  The tools library.                                                           /
/  Assorted utility routines for use in C programs.                             /
/  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "tools.h"

/* --------------------------------------------------------------------------
 **  Routine screen and process management.
 ** -------------------------------------------------------------------------
 */
/* ---------------------------------------------------------------------------  
** Print a neat header on the output.                                        
*/
void
banner( void ){   char date[16], time[9];
    when(date, time);
    printf( "\n----------------------------------------------------\n" );
    printf( "\t%s \n\t%s \n\t%s  %s\n", NAME, CLASS, date, time );
    printf( "----------------------------------------------------\n" );
}


 /* ---------------------------------------------------------------------------
 **  Print termination message.
 */
void bye( void ) { fputs( "\nNormal termination.\n", stderr ); }

/* --------------------------------------------------------------------------
**  Print message and wait for the user to type a newline.                     
*/
void 
hold( void )                                    
{   
    printf( "\n\n\aPress '.' and 'Enter' to continue.\n" );
    while ( getchar() != '.' )  				/* tight loop */ ;    
}                                                      

/* ---------------------------------------------------------------------------- 
** This function is for error messages.  
**    It takes a format argument followed by any number of data arguments.
**    It formats and prints an error message, then exits.                            **
*/
int
fatal (cstring format, ...)
{   va_list vargs;                               /* optional arguments */

    va_start(vargs, format);
    vfprintf(stderr, format, vargs);
    fprintf(stderr, "\a\a\n");
	hold();
    return (1);
}

/* ---------------------------------------------------------------------------- /
/  Routines for handling the time and date.                                     /
/ ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
** Store the current date and time in the arguments.  
**      System's date format is: "Fri Jun  9 10:15:55 1995\n"  
**      After extraction, date is: "Fri Jun  9 1995"    hour is: "10:15:55" 
*/
void 
when( char date[], char hour[] )
{   
    time_t now;          /* Stores an integer encoding of the date and time. */ 
    cstring nowstring;   /* Stores the date and time in a readable form.     */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);                   /* Convert to string form.    */
    strncpy( date, nowstring, 10);             /* Extract day, month, date.  */
    strncpy( &date[10], &nowstring[19], 5);    /* Extract space and year.    */
    date[15]  = '\0';                          /* Add the string terminator. */       
    strncpy( hour, &nowstring[11], 8);         /* Copy hour:minutes:seconds. */
    hour[8]  = '\0';                           /* Add the string terminator. */
}

/* --------------------------------------------------------------------------
** Store the current date in the argument and return a pointer to it. 
**      date format is: "Fri Jun  9 1995"                                    
*/
cstring
today( char date[] )
{   
    time_t now;          /* Stores an integer encoding of the date and time. */ 
    cstring nowstring;   /* Stores the date and time in a readable form.     */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);                   /* Convert to string form.    */
    strncpy( date, nowstring, 10);             /* Extract day, month, date.  */
    strncpy( &date[10], &nowstring[19], 5);    /* Extract space and year.    */
    date[15]  = '\0';                          /* Add the string terminator. */       
    return( date );  
}

/* --------------------------------------------------------------------------
** Store the current time in hour and return a pointer to it.   
**      hour format is: "10:15:55"                                           
*/
cstring
oclock( char hour[] )
{   
    time_t now;          /* Stores an integer encoding of the date and time. */ 
    cstring nowstring;   /* Stores the date and time in a readable form.     */

    now = time(NULL);              /* Get the date and time from the system. */
    nowstring = ctime(&now);              /* Convert to string form.         */
    strncpy( hour, &nowstring[11], 8);    /* Extract hour, minutes, seconds. */
    hour[8]  = '\0';                      /* Add the string terminator.      */
    return( hour );  
}

/* ---------------------------------------------------------------------------- /
/  Miscellaneous: menu handling and random selection.                           /
/  ----------------------------------------------------------------------------*/

