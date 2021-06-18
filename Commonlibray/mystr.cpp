/* strcat example */
#include <stdio.h>
#include <string.h>

char * mystrcat ( char * destination, const char * source )
{
	if((destination == NULL) || (source == NULL))
	{
       return NULL;
	} 
	
	char *tempTo = ( char *)destination;
    char *tempFrom = ( char *)source;
    while(*tempTo != '\0')
	{
    	tempTo++;
	}
    while((*tempTo++ = *tempFrom++) != '\0');
    return destination;  
}

int mystrcmp ( const char * s1, const char * s2 )
{	
	while(s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return *s1-*s2;
}

char * mystrcpy ( char * destination, const char * source )
{
	if((destination == NULL) || (source == NULL))
	{
       return NULL;
	} 
    size_t n = strlen(source);
    if(destination < source || destination > source + n)
    {
	    while(*source != '\0')
	    {
	    	*destination++ = *source++;
		}
	}
	else if(destination > source)
	{
		char *tempTo = ( char *)destination + n -1;
    	char *tempFrom = ( char *)source + n -1;
    	while(n-- > 0)
	    {
	    	*tempTo-- = *tempFrom--;
		}
    	
	}
    return destination;
    
}


int main ()
{
  char str[80];
  mystrcpy (str,"These ");
  mystrcat (str,"strings ");
  mystrcat (str,"are ");
  mystrcat (str,"concatenated.");
  int ret = mystrcmp(str,"These t");
  puts (str);
  printf("%d",ret);
  return 0;
}