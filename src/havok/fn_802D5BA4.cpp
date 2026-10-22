#pragma force_active on
extern char lbl_80410C88[];

struct Obj {
    virtual void v0();
    virtual void v1(const char*, int, void*);
    virtual void v2(const char*, int, int, int, int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct Data {
    char pad[0x34];
    int a;
    int b;
    unsigned c;
};

extern "C" void fn_802D5BA4(Data* d, Obj* o) {
    o->v1(lbl_80410C88, 1, d);
    unsigned c = d->c;
    const char* s = lbl_80410C88 + 10;
    if ((c & 0x80000000) == 0) {
        o->v2(s, 1, d->a, d->b * 0x30, (c & 0x3fffffff) * 0x30);
    }
    o->v6();
}
