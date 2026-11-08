#include <string.h>
#pragma force_active on
typedef struct { int a; int b; } Pair;
typedef struct { char pad[12]; Pair pair; } Input;
extern int fn_80372E1C(void *, const char *, int);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern void *fn_8035DFE8(int);
extern void fn_803732E0(void *, const void *);
extern int fn_8036ABB0(void *, Pair, void *, void *, int);
extern void fn_8036EEE4(void *, void *);
extern char lbl_8059F870[6];
extern char lbl_8048F74C[];
extern char lbl_8048F788[];
int fn_803707AC(void **arg0, Input *arg1, const char *arg2)
{
    char *data;
    Pair pair;
    Pair *p;
    int ret;
    data = *arg0;
    if (fn_80372E1C(arg0, arg2, 1)) return 4;
    if (strncmp(arg2, lbl_8059F870, 5) != 0) {
        fn_80373290(arg0, 1, lbl_8048F74C);
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    pair = arg1->pair;
    if (pair.a) {
        p = fn_8035DFE8(8);
        if (!p) {
            fn_803732E0(arg0, lbl_8048F788);
            return 1;
        }
        p->b = *(int *)(data + 0x1A0);
        p->a = 0;
        ret = fn_8036ABB0(arg0, pair, p, arg1, 0);
        if (ret) return ret;
    }
    fn_8036EEE4(arg0, arg1);
    return 0;
}
