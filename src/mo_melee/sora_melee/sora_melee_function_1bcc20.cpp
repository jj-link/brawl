#pragma force_active on
struct Ent { char pad[0xA]; short val; };
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual Ent* get(int);
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
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int test(int);
    char pad[0xC];
    Sub sub;
    char pad2[0x128];
    unsigned char flag;

    int find(int c) {
        if (c <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            int v = sub.get(i)->val;
            if (v <= -1) return i;
            if (v > c) return i;
        }
        return n;
    }
};
extern "C" int fn_27_1BD428(void*);
extern "C" void fn_27_FE124(void*, int, int, short*, int);

extern "C" int fn_27_1BCC20(Obj* self, int a, int b, short* h, int c) {
    short s;
    int out[5];
    if (self->sub.full() == 1U) return -1;
    if ((self->flag == 0 || b > -1) && self->test(b) == 1U) return -1;
    if (self->flag == 0 && b <= -1) {
        b = fn_27_1BD428(self);
        if (b <= -1) return -1;
    }
    int idx = self->find(c);
    if (idx < 0) return -1;
    s = *h;
    fn_27_FE124(out, a, b, &s, c);
    self->sub.set(idx, out);
    return b;
}
