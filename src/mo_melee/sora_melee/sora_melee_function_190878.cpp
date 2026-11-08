#pragma force_active on

class Iface70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void f5(int a, void* b, void* c);
};

class Iface64 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void f7(int a, int b);
};

struct Ctx {
    char pad0[0x64];
    Iface64* m64;
    char pad1[0x70 - 0x68];
    Iface70* m70;
};

struct Outer {
    char pad[0xd8];
    Ctx* ctx;
};

extern "C" {
int fn_27_190878(void* unused, Outer* self) {
    Ctx* c = self->ctx;
    Iface70* a = c->m70;
    Iface64* b = c->m64;
    a->f5(0xFE, self, c);
    b->f7(2, 0x20000000);
    b->f7(0, 0x20000001);
    b->f7(0, 0x20000002);
    return 1;
}
}
