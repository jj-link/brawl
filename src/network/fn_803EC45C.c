#pragma force_active on
extern int fn_8020D250(char *);
extern int fn_8020B9BC(char *, char *, int);
extern int fn_803EC51C(char *);
extern char lbl_80598098[0x40];
struct Obj { char pad[0xe4]; int flags; };
int fn_803EC45C(int arg0, struct Obj *arg1, int arg2) {
    int result;
    result = fn_8020D250(lbl_80598098);
    if (result != 0) return result;
    if (arg1->flags & 4) result = 0;
    else result = fn_8020B9BC((char *)arg1 + 4, (char *)arg1 + 0x58, 3);
    if (arg2 != 0) result = -12;
    switch (result) {
    case -12:
        result = fn_803EC51C((char *)arg1);
        if (result == 0) *(int *)arg1 = arg0;
        break;
    case 0:
        *(int *)arg1 = arg0;
        result = 0;
        break;
    }
    return result;
}