#pragma force_active on
#include <types.h>

extern "C" {
u8 fn_27_1119B8(void*);
u32 fn_27_111E30(void*);
u32 fn_27_14583C(void*, s32, u32);
void* getOwner__9ftManagerFi(void*, s32);
}

extern u8 g_ftCommonDataAccesser[];
extern void* g_ftManager;

class VtA {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual s32 get(s32);
};

class VtB {
public:
    u8 pad[0x3c];
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual s32 get();
};

struct Inner {
    u8 pad[0x64];
    VtA* a;
};

struct Data {
    u8 pad0[8];
    VtB* b;
    u8 pad1[0xcc];
    Inner* inner;
};

struct Self {
    u8 pad[8];
    Data* data;
};

extern "C" void fn_27_14DB54(Self* __restrict self) {
    s32 id = self->data->inner->a->get(0x10000000);
    void* owner = getOwner__9ftManagerFi(g_ftManager, id);
    u8 flags = fn_27_1119B8(owner);
    if (fn_27_111E30(owner) == 1) {
        flags |= 0x80;
    }
    s32 r = self->data->b->get();
    fn_27_14583C(g_ftCommonDataAccesser, r, flags);
}
