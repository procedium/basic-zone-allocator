#ifndef ZONE_H
#define ZONE_H

#include <stdint.h>

typedef struct Zone Zone;
struct Zone {
	char *beg;
	char *used;
	char *end;
	void (*oom)();
};


// NOTE: the program will be stuck if `oom` returns.
Zone get_zone(void (*oom)(), void *beg, void *end);
void *zone_alloc(Zone *z, ptrdiff_t sz);
void reset_zone(Zone *z);

#endif
