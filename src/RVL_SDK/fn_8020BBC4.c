#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Obj {
    int field0;
    int (*cb)(int, struct Obj *);
    char *p8;
} Obj;

void fn_8020BBC4(int arg0, Obj *arg1) {
    int result;
    if (arg0 >= 0) {
        *(int *)arg1->p8 = arg0;
        arg1->p8[0x89] = 2;
        arg1->p8[0x8A] = 1;
        arg1->cb(0, arg1);
        return;
    }
    result = fn_8020CAEC(arg0);
    arg1->cb(result, arg1);
}