#include <iostream>
#include "vect.h"
#include <stdlib.h>  



int main() {
	int t[2] = {1,2};
	vect <int> a(2, t);
	
	int y[1] = {1};
	vect <int> b(1, y);


	b.pop_back();
	printf("%d", a==b);


	

	return 0;
}
