#include <types.h>
#pragma force_active on

extern "C" void fn_27_A403C(void* self);

class Module {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFlag(s32 a, u32 b);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void setName(u32 id, void* owner);
};

struct Holder {
    char pad[0x64];
    Module* mod;
};

struct Sub {
    char pad[0xd8];
    Holder* holder;
};

struct Owner {
    char pad[0x48];
    Sub* sub;
};

extern "C" void fn_27_14E348(Owner* self) {
    fn_27_A403C(self);
    self->sub->holder->mod->setFlag(-1, 0x10000008);
    self->sub->holder->mod->setFlag(-1, 0x10000007);
    self->sub->holder->mod->setName(0x12000005, self->sub);
}
