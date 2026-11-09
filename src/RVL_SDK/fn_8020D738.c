#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Obj {
    int field0;
    int (*cb)(int, struct Obj *);
    char pad8[0x80];
    char *x88;
} Obj;

void fn_8020D738(int arg0, Obj *arg1) {
    int r = arg0;
    int result;

    if (arg0 == 0 || arg0 == -0x66) {
        r = 0;
        *arg1->x88 = 2;
    } else if (arg0 == -0x65) {
        r = 0;
        *arg1->x88 = 1;
    }
    result = fn_8020CAEC(r);
    arg1->cb(result, arg1);
}
