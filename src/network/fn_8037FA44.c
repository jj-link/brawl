#include <types.h>
#pragma force_active on
typedef struct Entry { int *type; int unk4; void *file; } Entry;
typedef struct Other { void *data; char pad[0x14]; int flag; } Other;
typedef struct Object { char pad[0x160]; Other *other; void *array; } Object;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern void fn_8035A4FC(void *);
extern void fn_8035E00C(void *);
extern int fn_803F5898(void *);
void fn_8037FA44(Object *self) {
    int count, i;
    Entry *entry;
    if (self->array != 0) {
        count = fn_8035A590(self->array);
        for (i = 0; i < count; i++) {
            entry = fn_8035A598(self->array, i);
            if (*entry->type != 0 && *entry->type == 1) {
                if (entry->file != 0) {
                    fn_803F5898(entry->file);
                }
                entry->file = 0;
            }
        }
        fn_8035A4FC(self->array);
        self->array = 0;
    }
    count = (int)self->other;
    if (count != 0 && ((Other *)count)->flag != 0) {
        fn_8035A4FC(((Other *)count)->data);
        fn_8035E00C((void *)count);
        self->other = 0;
    }
}