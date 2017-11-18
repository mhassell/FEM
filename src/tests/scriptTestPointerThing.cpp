// testing if a declared (but not new'd and assigned) pointer is NULL

#include <iostream>
#include <cassert>

int main(){

	int* value;

	assert(value == NULL); // this checks that the pointer was defined but is not allocated
	
	value = new int;
	*value = 7;	

	assert(value != NULL);  // check that value was assigned to memory

	assert(*value == 7);	// and check that it now points to something

	delete value;

	// assert(value==NULL);    // check that it is null again (not the case, fails at runtime)

	value = new int;

	*value = 7;

	delete[] value;  // valgrind gives some interesting warnings

}
