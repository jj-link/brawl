#pragma force_active on
extern "C" void fn_802DD888(void* self, unsigned int arg);
extern "C" void fn_802E4140(void* self, void* ctx);
extern "C" void fn_802EA884(void* p);
extern "C" void fn_802F4458(void* self, void* ctx);
extern "C" void fn_802F8EC0(void* a, void* b);

struct Obj08 {
    char pad0[0x9C];
    int m9C;
};

struct Obj {
    char pad0[0x58];
    Obj* m58;
    char pad1[0x1B8 - 0x5C];
    int m1B8;
};

struct Ptr3C {
    char pad0[4];
    unsigned short u4;
    unsigned short u6;
};

struct Ctx {
    unsigned short arg;
    unsigned short pad2;
    unsigned int size;
    void* a;
    void* b;
    void* c;
    void* self;
};

class Class_804878D0 {
public:
    virtual void fn_802D8204();
    virtual void fn_802D9350();
    virtual void fn_802D873C();
    virtual void fn_802D830C();
    virtual void vfn_802D8CDC();
    virtual void fn_802D8F40();
    virtual void fn_802D942C();
    virtual void fn_802D8340();
    virtual void fn_802D851C();
    virtual void fn_802D85DC();
    virtual int fn_802D8E4C(unsigned int arg);

    char pad04[4];
    Obj08* m08;
    char pad0C[4];
    char m10[0xC];
    unsigned char* m1C;
    char pad20[0x1C];
    Ptr3C* m3C;
    char m40[0x14];
    Obj* m54;
    Obj* m58;
};

extern "C" void fn_802D8CDC(Class_804878D0* self, unsigned int arg) {
    Ctx ctx;
    unsigned int size;
    Obj* p54;
    Obj* p58;
    Ptr3C* p3c;

    p54 = self->m54;
    p58 = self->m58;
    p3c = self->m3C;
    size = self->m1C[arg] * 0x14 + ((((unsigned int)p3c + 0x37) & ~0xF) + (p3c->u6 << 5));
    if (size != 0) {
        size += 8;
    }
    ctx.arg = (unsigned short)arg;
    ctx.size = size;
    ctx.a = p54;
    ctx.b = p58;
    ctx.self = self;
    if (arg != 0xFFFF) {
        int r = self->fn_802D8E4C(arg);
        if (r != 0) {
            r += 8;
        }
        ctx.size = r;
    }
    fn_802F4458(self->m08, &ctx);
    if (p54->m1B8 != 0) {
        fn_802E4140(p54, &ctx);
    }
    if (p58->m1B8 != 0) {
        fn_802E4140(p58, &ctx);
    }
    fn_802DD888(self->m10, arg);
    if (self->m3C->u4 == 0) {
        if (self->m08->m9C == 0) {
            fn_802F8EC0(self->m08, self->m40);
            return;
        }
        fn_802EA884(p54->m58);
        fn_802EA884(p58->m58);
        fn_802F8EC0(self->m08, self->m40);
    }
}
