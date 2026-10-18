#pragma force_active on
extern "C" void fn_27_1C608(void*);

struct V {
    char pad[8];
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void call(unsigned int, unsigned int, int);
};

struct Inner {
    V* v;
};

struct Mid {
    char pad[0xD8];
    Inner* inner;
};

struct Obj {
    char pad[0x168];
    Mid* mid;
    int x;
    int frame;
    unsigned int unk174;
};

extern "C" void fn_27_1F210(Obj* self, unsigned int a, int frame) {
    if (self->unk174 != 0xFFFF && frame >= self->frame) {
        self->mid->inner->v->call(a, self->unk174, 1);
    } else {
        fn_27_1C608(self);
    }
}
