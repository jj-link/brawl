#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Obj {
    int field0;
    int (*cb)(int, struct Obj *);
    char *p8;
} Obj;

void fn_8020C614(int arg0, Obj *arg1) {
    if (arg0 == 0) {
        arg1->p8[0x89] = 7;
        arg1->p8[0x8A] = 4;
    }
    arg1->cb(fn_8020CAEC(arg0), arg1);
}
