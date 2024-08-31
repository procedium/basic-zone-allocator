#include "zone.h"

Zone get_zone(void (*oom)(), void *beg, void *end)
{
	Zone z;

	z.beg  = (char*) beg;
	z.used = (char*) beg;
	z.end  = (char*) end;
	z.oom  = oom;

	return z;
}

void *zone_alloc(Zone *z, ptrdiff_t sz)
{
	if (z->end - z->used <= sz) {
		z->oom();
		return NULL;
	}

	char *p = z->used;
	z->used += sz;

	for (ptrdiff_t i = 0; i < sz; i++) {
		p[i] = 0;
	}

	return p;
}

void reset_zone(Zone *z)
{
	z->used = z->beg;
}
