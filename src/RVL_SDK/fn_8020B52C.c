#pragma force_active on
extern void fn_8020B2F8(unsigned char *, unsigned long, unsigned long, unsigned long);
extern int fn_8020CAEC(int);

typedef struct Obj {
    int field0;
    void (*cb)(int, struct Obj *);
    char pad[0xc];
    unsigned char *data;
    char pad18[8];
    unsigned long value;
    unsigned long a;
    unsigned long b;
    unsigned long c;
} Obj;

void fn_8020B52C(int arg0, Obj *arg1) {
    if (arg0 == 0) {
        unsigned char *p = arg1->data;
        p[6] = arg1->value;
        fn_8020B2F8(p + 7, arg1->a, arg1->b, arg1->c);
    }
    arg1->cb(fn_8020CAEC(arg0), arg1);
}