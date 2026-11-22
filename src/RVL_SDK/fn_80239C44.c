#pragma force_active on
#include <types.h>

extern char lbl_80529CF8[];
extern void *fn_80239F18(void *);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern char *strncpy(char *, const char *, unsigned long);

static inline u8 *find_entry(const void *a, int i)
{
    u8 *p = (u8 *)lbl_80529CF8 + 0x1F30;
    while (i < 16) {
        if ((p[0x76] & 0x80) && fn_803F6150(p + 0x1C, a, 6) == 0)
            return p;
        i++;
        p += 0x88;
    }
    return 0;
}

int fn_80239C44(void *a, void *b, u8 *c, void *d, int *e, void *f)
{
    u8 *p = find_entry(a, 0);

    if (p == 0) {
        p = fn_80239F18(a);
        if (p == 0)
            return 0;
    } else {
        *(int *)(p + 0x0C) = (*(int *)(lbl_80529CF8 + 0x1974))++;
    }

    if (b)
        memcpy(p + 0x22, b, 3);

    memset(p + 0x35, 0, 0x41);
    if (c && *c) {
        p[0x76] |= 8;
        strncpy((char *)(p + 0x35), (char *)c, 0x40);
    }

    if (d)
        memcpy(p + 0x77, d, 8);
    else
        memset(p + 0x77, 0, 8);

    *(int *)(p + 0x10) = e[0];
    *(int *)(p + 0x14) = e[1];

    if (f) {
        p[0x76] |= 0x10;
        memcpy(p + 0x25, f, 0x10);
    }

    return 1;
}