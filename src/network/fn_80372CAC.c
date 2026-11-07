#include <string.h>
#pragma force_active on
typedef struct Pair { int a; int b; } Pair;
typedef struct Obj { char pad[12]; Pair pair; } Obj;
extern int fn_80372E1C(void *, const char *, int);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern void *fn_8035DFE8(int);
extern void fn_803732E0(void *, const char *);
extern int fn_8036ABB0(void *, Pair, void *, Obj *, int);
extern void fn_8036EEE4(void *, Obj *);
extern char lbl_8059F960[5];
extern char lbl_8048FB20[];
extern char lbl_8048FB50[];
int fn_80372CAC(void *arg0, Obj *arg1, const char *arg2) {
    Pair pair;
    int *p;
    int result;
    if (fn_80372E1C(arg0, arg2, 1)) return 4;
    if (strncmp(arg2, lbl_8059F960, 4)) {
        fn_80373290(arg0, 1, lbl_8048FB20);
        fn_8036AAF0(arg0, 3, 1);
        return 3;
    }
    pair = arg1->pair;
    if (pair.a) {
        p = fn_8035DFE8(4);
        if (!p) {
            fn_803732E0(arg0, lbl_8048FB50);
            return 1;
        }
        *p = 0;
        result = fn_8036ABB0(arg0, pair, p, arg1, 0);
        if (result) return result;
    }
    fn_8036EEE4(arg0, arg1);
    return 0;
}