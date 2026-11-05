#include <stdio.h>
#pragma force_active on
extern char lbl_8059F954[7];
extern char lbl_8059F950[4];
extern char lbl_8048FB10[];
extern char lbl_8048FAF8[];
extern int fn_80372F14(const char *, const char *, char *, int);
extern int fn_80370274(int, void *, int, const int *);
extern int fn_8036A680(int, void *, const char *);
extern int fn_803702DC(int, void *, const char *, int);
void fn_80372BC4(int a, void *b, int c, const char *d) {
    char buf[64];
    char out[32];
    unsigned int z, y;
    int x;
    if (fn_80372F14(d, lbl_8059F954, buf, 64) != 0 &&
        sscanf(buf, lbl_8048FB10, &x, &y, &z) == 3) {
        const char *empty = lbl_8059F950;
        if (fn_80370274(a, b, 201, &x) == 0) {
            sprintf(out, lbl_8048FAF8, 1, 2);
            if (fn_8036A680(a, b, out) == 0) {
                fn_803702DC(a, b, empty, -1);
            }
        }
    }
}