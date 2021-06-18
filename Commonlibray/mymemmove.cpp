/* memmove example */
#include <stdio.h>
#include <string.h>

void * mymemmove ( void * destination, const void * source, size_t num )
{
	if((destination == NULL) || (source == NULL))
	{
       return NULL;
	} 
	
	char *tempTo = ( char *)destination;
    char *tempFrom = ( char *)source;
    
    if(source>destination||(source+num)<destination) 
    {
	    while(num-- > 0)
	    {
	    	*tempTo++=*tempFrom++;
		}
	}
	else if(source < destination)
	{
		char *tempFrom =( char *)destination + num -1;
		char *tempTo = ( char *)source + num -1;
		while(num-- > 0)
	    {
	    	*tempTo--=*tempFrom--;
		}
	}
	return destination;
    
    
}


int main ()
{
  char str[] = "123456789";
  puts (str);
  mymemmove (str+5,str+6,3);
  puts (str);
  return 0;
}