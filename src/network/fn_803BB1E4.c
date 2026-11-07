#include <types.h>
#pragma force_active on
typedef struct Param {
    char pad[0x228];
    int f228;
    unsigned int f22c;
    int f230;
    unsigned int f234;
    unsigned int f238;
    unsigned short f23c;
    unsigned short f23e;
} Param;
typedef struct Entry {
    unsigned int flags;
    char pad04[0x1c];
    unsigned int *buffer;
    unsigned short f24, f26;
    unsigned int f28, f2c, f30;
    char pad34[8];
    Param param;
    unsigned short f27c, f27e;
    unsigned int f280, f284, f288;
    unsigned short count;
    unsigned short pad28e;
} Entry;
typedef struct Manager {
    char pad[0x40];
    Entry entries[5];
    char pad_d10[0xb70];
    unsigned short flags, f1882;
    unsigned int *buffer;
    unsigned int size;
} Manager;
extern int fn_803B847C(void *, void *, unsigned int, void *);
extern void *fn_803A976C(void *, int, unsigned int);
Entry *fn_803BB1E4(Manager *m, Param *p) {
    int freeIndex = 0;
    Entry *freeEntry = 0;
    Manager *walk = m;
    Entry *e = &m->entries[0];
    int i;
    for (i = 0; i < 5; i++) {
        if (!(walk->entries[0].flags & 1) || ((walk->entries[0].flags & 1) && ((walk->entries[0].flags == 0) & 2))) {
            if (!freeEntry) {
                freeEntry = e;
                freeIndex = i;
            }
        } else if (p->f22c == walk->entries[0].param.f22c && p->f238 == walk->entries[0].param.f238 && p->f23c == walk->entries[0].param.f23c) {
            m->entries[i].count++;
            return &m->entries[i];
        }
        walk = (Manager *)((char *)walk + 0x290);
        e++;
    }
    if (!freeEntry) return 0;
    freeEntry->flags = 3;
    freeEntry->count = 1;
    freeEntry->param = *p;
    freeEntry->f27c = 0;
    freeEntry->f27e = 0;
    freeEntry->f280 = 0;
    freeEntry->f284 = 0;
    freeEntry->f288 = 0;
    fn_803B847C((char *)freeEntry + 4, 0, p->f22c, (char *)freeEntry + 0x270);
    if (m->flags & 1) {
        freeEntry->buffer = m->buffer + freeIndex * m->size;
        fn_803A976C(freeEntry->buffer, 0, m->size * 4);
        freeEntry->f2c = m->size;
        freeEntry->f24 = m->f1882;
        freeEntry->f26 = 0;
        freeEntry->f28 = 0;
        freeEntry->f30 = 0;
        if (p->f228 && freeEntry->f2c) {
            freeEntry->buffer[0] = p->f234;
            freeEntry->f28++;
        }
    }
    return freeEntry;
}