#pragma force_active on

struct Base50 {
    char pad0[0x50];
};

struct Obj : Base50 {
    virtual void f0(int);
    virtual void f1();
    virtual void f2();
};

struct Entry {
    int state;
    int a;
    int b;
    char pad[0x58 - 12];
};

struct Sub {
    char pad0[0x5c];
    unsigned char flag5c;
    char pad1[0x60 - 0x5d];
    int f60;
    char pad2[0xe4 - 0x64];
    Obj* e4;
    char pad3[0xec - 0xe8];
    int fec;
};

struct Self {
    char pad0[0x40];
    int f40;
    int f44;
    char pad1[0x68 - 0x48];
    Sub* f68;
    char pad2[0x70 - 0x6c];
    Entry elems[1];
};

extern "C" void fn_11_7E7C(void* self, Obj* obj, int a, int b, Entry* e);

extern "C" int fn_11_832C(Self* self) {
    Sub* sub = self->f68;
    int idx = self->f44;
    if (sub->flag5c == 0) {
        return self->f40;
    }
    int r6 = 1;
    Entry* e = &self->elems[idx];
    if (sub->f60 == 0 && sub->fec == 6) {
        Obj* o = sub->e4;
        fn_11_7E7C(self, o, e->a, e->b, e);
        if (o != 0) {
            o->f0(1);
        }
        r6 = 0;
    }
    if (e->state == 5) {
        e->state = 0;
    } else {
        int s = 3;
        if (r6 != 0) {
            s = 4;
        }
        e->state = s;
    }
    return 5;
}
