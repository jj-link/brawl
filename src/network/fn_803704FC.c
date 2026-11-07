#include <string.h>
#include <stdlib.h>
#pragma force_active on
typedef struct { int a; int b; } Pair;
typedef struct { char pad[12]; Pair pair; } Input;
typedef struct { int a; int b; } Result;
extern char lbl_8048F648[];
extern char lbl_8059F868[6];
extern int fn_80372E1C(void *, const char *, int);
extern int fn_80372F14(const char *, const char *, char *, int);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern void *fn_8035DFE8(int);
extern void fn_803732E0(void *, const char *);
extern int fn_8036ABB0(void *, Pair *, void *, void *, int);
extern void fn_8036EEE4(void *, void *);
int fn_803704FC(void *ctx, Input *arg, const char *str)
{
    char *base = lbl_8048F648;
    char buf[16];
    Pair pair, copy;
    Result *p;
    int value, ret;
    if (fn_80372E1C(ctx, str, 1)) return 4;
    if (strncmp(str, lbl_8059F868, 5) != 0) {
        fn_80373290(ctx, 1, base + 0x104);
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }
    if (!fn_80372F14(str, base + 0x134, buf, 16)) {
        fn_80373290(ctx, 1, base + 0x104);
        fn_8036AAF0(ctx, 3, 1);
        return 3;
    }
    value = atoi(buf);
    pair = arg->pair;
    if (pair.a) {
        p = fn_8035DFE8(8);
        if (!p) {
            fn_803732E0(ctx, base + 0x140);
            return 1;
        }
        p->b = value;
        p->a = 0;
        copy = pair;
        ret = fn_8036ABB0(ctx, &copy, p, arg, 0);
        if (ret) return ret;
    }
    fn_8036EEE4(ctx, arg);
    return 0;
}