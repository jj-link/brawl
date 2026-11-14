#include <types.h>
#pragma force_active on
typedef struct { int pad[2]; void *array; } Self;
typedef struct { char *str; int count; } Entry;
typedef struct { char *str; int type; } Item;
extern void *fn_8035A460(int, int, int);
extern void fn_8035A4FC(void *);
extern int fn_8035A590(void *);
extern Item *fn_8035A598(void *, int);
extern void fn_8035A5C8(void *, Item *);
extern void *fn_80388590(Self *);
extern Entry *fn_8035B1C4(void *, char **);
extern void fn_8035B120(void *, char **);
extern void fn_8035B078(void *, Entry *);
extern char *fn_8035D654(const char *);
int fn_8038C160(Self *self, unsigned char *data, int size) {
    struct { Entry local; char *old; int padding; Item item; } frame;
    Entry *entry;
    int i, j, n, length, k;
    int count = *data++;
    size--;
    if (self->array) {
        if (self->array) {
            for (i = 0; i < fn_8035A590(self->array); i++) {
                frame.old = fn_8035A598(self->array, i)->str;
                entry = fn_8035B1C4(fn_80388590(self), &frame.old);
                if (entry && --entry->count == 0)
                    fn_8035B120(fn_80388590(self), &frame.old);
            }
            fn_8035A4FC(self->array);
            self->array = 0;
        }
    }
    self->array = fn_8035A460(8, count, 0);
    if (!self->array) return 5;
    for (k = 0; k < count; k++) {
        if (size < 2) return 4;
        for (j = 0; j < size - 1; j++) {
            if ((signed char)data[j + 1] == 0) {
                length = j + 1;
                goto found;
            }
        }
        length = -1;
found:
        if (length == -1) return 4;
        frame.item.type = *data;
        frame.local.str = (char *)data + 1;
        entry = fn_8035B1C4(fn_80388590(self), &frame.local.str);
        frame.item.str = entry ? (entry->count++, entry->str) :
            (frame.local.str = fn_8035D654((char *)data + 1),
             frame.local.count = 1,
             fn_8035B078(fn_80388590(self), &frame.local),
             frame.local.str);
        fn_8035A5C8(self->array, &frame.item);
        data += length + 1;
        size -= length + 1;
    }
    return 0;
}
