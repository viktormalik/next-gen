#include <string.h>

struct bus {
	int x; struct bus* y ;
};

int main () {
	struct bus trup;
	memset (&trup, 0 , sizeof(struct bus));
	return 0;
}
