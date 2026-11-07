#include <string.h>
#pragma force_active on
typedef struct Entry { int *info; int unk4; void *file; int unkC; } Entry;
typedef struct Config { void *array; int a, b, c; } Config;
typedef struct Object { char pad[0x160]; Config *config; void *array; int a, b, result, c, d, flag, e; } Object;
extern int fn_8035A590(void *);
extern void *fn_8035A460(int, int, int);
extern Entry *fn_8035A598(void *, int);
extern int fn_8037F7D8(Entry *);
extern void fn_803F5898(void *);
extern void fn_8035A4FC(void *);
extern void fn_8035A5C8(void *, void *);
extern int fn_8037F458(Object *);
extern int fn_8037F394(Object *);
int fn_8037F894(Object *self) {
    int count, i, result;
    Entry entry;
    Entry *p;
    Config *config = self->config;
    if (config == 0) return 0;
    self->a = 0;
    self->b = 0;
    self->result = 0;
    self->e = 0;
    self->c = config->a;
    self->d = config->b;
    count = fn_8035A590(config->array);
    self->array = fn_8035A460(0x10, count, 0);
    if (self->array == 0) return 0;
    for (i = 0; i < count; i++) {
        p = fn_8035A598(self->config->array, i);
        memset(&entry, 0, 0x10);
        entry.info = (int *)p;
        if (fn_8037F7D8(&entry) == 0) {
            for (i--; i >= 0; i--) {
                p = fn_8035A598(self->array, i);
                if (*p->info != 0 && *p->info == 1) {
                    if (p->file != 0) fn_803F5898(p->file);
                    p->file = 0;
                }
            }
            fn_8035A4FC(self->array);
            self->array = 0;
            return 0;
        }
        fn_8035A5C8(self->array, &entry);
    }
    if (self->config == 0) result = 0;
    else if (self->config->c != 0) result = fn_8037F458(self);
    else result = fn_8037F394(self);
    self->result = result;
    self->flag = 1;
    return 1;
}