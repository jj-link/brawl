#pragma force_active on
extern int fn_8020CAEC(int);

typedef struct Inner {
    char pad[0x89];
    unsigned char b89;
    unsigned char b8a;
} Inner;

typedef struct Obj {
    int field0;
    int (*cb)(int, struct Obj *);
    Inner *inner;
} Obj;

void fn_8020C670(int arg0, Obj *arg1) {
    if (arg0 == 0) {
        arg1->inner->b89 = 7;
        arg1->inner->b8a = 2;
    }
    {
        int result = fn_8020CAEC(arg0);
        arg1->cb(result, arg1);
    }
}
