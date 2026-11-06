#include <string.h>
#pragma force_active on
typedef struct { int type; char *name; void *data; int length; int unused; int count; } Entry;
typedef struct { void *list; } Container;
typedef struct { char padding[0x160]; Container *container; } Object;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern int fn_80362F5C(void *);
int fn_8037F394(Object *self) {
    Container *container = self->container;
    int i;
    int total = 0;
    int count = fn_8035A590(container->list);
    Entry *entry;
    if (count == 0) return 0;
    for (i = 0; i < count; i++) {
        entry = fn_8035A598(container->list, i);
        if (entry->type == 0) {
            total += strlen(entry->name);
            total += entry->length;
            total += entry->count * 2;
            total++;
        } else if (entry->type == 3) {
            total += fn_80362F5C(entry->data);
        }
    }
    return total + count - 1;
}