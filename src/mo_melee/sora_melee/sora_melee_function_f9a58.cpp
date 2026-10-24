#pragma force_active on

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual short* get(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void set(int, void*);
    virtual void v12();
    virtual void v13();
    virtual unsigned int full();
};

struct Out {
    unsigned int a;
    int b;
    short c;
    short d;
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int test(int);
    virtual void v7();
    char pad[12];
    Sub sub;
    char pad2[0x14];
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

extern "C" int fn_27_FA260(Obj*);
extern "C" void fn_27_FE174(Out*, int, int, short*, int);

extern "C" int fn_27_F9A58(Obj* self, int a, int b, short* h, int c) {
    if (self->sub.full() == 1U) return -1;
    if (self->flag == 0 || b > -1) {
        if (self->test(b) == 1U) return -1;
    }
    if (self->flag == 0 && b <= -1) {
        b = fn_27_FA260(self);
        if (b <= -1) return -1;
    }
    int idx = self->find(c);
    if (idx < 0) return -1;
    short s = *h;
    Out o;
    fn_27_FE174(&o, a, b, &s, c);
    self->sub.set(idx, &o);
    return b;
}
