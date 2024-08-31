#include <stdio.h>
#include <stdlib.h>

#include "zone.h"


void failure(void)
{
	fprintf(stderr, "OOM!\n");
	exit(1);
}

int main(int argc, char **argv)
{
	#define mem_sz (20)

	static
	char mem[mem_sz];
	Zone zone = get_zone(failure, mem, mem + mem_sz);

	for (int i = 0; i < argc; i++) {
		(void) zone_alloc(&zone, sizeof *x);
	}

	printf("success!\n");
	return 0;
}
