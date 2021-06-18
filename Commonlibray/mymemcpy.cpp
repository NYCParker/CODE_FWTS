/* memcpy example */
#include <stdio.h>
#include <string.h>

struct {
  char name[40];
  int age;
} person, person_copy;


void * mymemcpy ( void * destination, const void * source, size_t num )
{
	 if((destination == NULL) || (source == NULL))
	 {
	       return NULL;
	 } 
	
	char *tempTo = ( char *)destination;  // 保存memFrom的首地址
    char *tempFrom = ( char *)source;  // 保存memTo的首地址 
	while(num-- > 0)
	{
		*tempTo++=*tempFrom++;
	}
	return destination;
}

int main ()
{
  char myname[] = "Pierre de Fermat";

  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 42;

  /* using memcpy to copy structure: */
  mymemcpy ( &person_copy, &person, sizeof(person) );

  printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}