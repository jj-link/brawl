#pragma force_active on
struct Sub {
    virtual void v0(); virtual void v1();
    virtual short* get(int);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v8b(); virtual void v8c();
    virtual void set(int, void*);
    virtual void v12(); virtual void v13();
    virtual unsigned int full();
};
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int check(int);
    char padx[0xC];
    Sub sub;
    char pad[0x110];
    unsigned char flag;

    int find(int c) {
        if (c <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            short v = sub.get(i)[5];
            if (v <= -1) return i;
            if (v > c) return i;
        }
        return n;
    }
};
struct Out { int a[3]; };
extern "C" int fn_27_F84B4(Obj*);
extern "C" void fn_27_FE124(Out*, int, int, short*, int);

extern "C" int fn_27_F7CAC(Obj* self, int a, int b, short* h, int c) {
    if (self->sub.full() == 1U) return -1;
    if (self->flag == 0 || b > -1) {
        if (self->check(b) == 1U) return -1;
    }
    if (self->flag == 0 && b <= -1) {
        b = fn_27_F84B4(self);
        if (b <= -1) return -1;
    }
    int idx = self->find(c);
    if (idx < 0) return -1;
    short s = *h;
    Out o;
    fn_27_FE124(&o, a, b, &s, c);
    self->sub.set(idx, &o);
    return b;
}
