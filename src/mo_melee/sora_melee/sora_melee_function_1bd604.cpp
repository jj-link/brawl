#pragma force_active on
struct Entry { char pad[0xA]; short val; };
struct Module {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int);
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
struct Owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int test(int);
    char pad[0xC];
    Module mod;
    char pad2[0xF8];
    unsigned char flag;
    int find(int c) {
        if (c <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            int v = mod.get(i)->val;
            if (v <= -1) return i;
            if (v > c) return i;
        }
        return n;
    }
};
extern "C" int fn_27_1BDE0C(Owner*);
extern "C" void fn_27_FE124(int*, int, int, short*, int);

extern "C" int fn_27_1BD604(Owner* self, int id, int slot, short* half, int arg4)
{
    if (self->mod.full() == 1U) return -1;
    if (self->flag == 0 || slot > -1) {
        if (self->test(slot) == 1U) return -1;
    }
    if (self->flag == 0 && slot <= -1) {
        slot = fn_27_1BDE0C(self);
        if (slot <= -1) return -1;
    }
    int idx = self->find(arg4);
    if (idx < 0) return -1;
    short s = *half;
    int out[3];
    fn_27_FE124(out, id, slot, &s, arg4);
    self->mod.set(idx, out);
    return slot;
}
