#include <types.h>
#pragma force_active on

struct fn27Inner {
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(s32 arg, u32 flags);
};

struct fn27Mid {
    char pad[0x64];
    fn27Inner* m64;
};

struct fn27Outer {
    char pad[0xd8];
    fn27Mid* md8;
};

struct fn27Top {
    char pad[0x60];
    fn27Outer* m60;
};

extern "C" {
s32 fn_27_29B794(void* unused, fn27Top* self) {
    self->m60->md8->m64->unk1C(-1, 0x10000000);
    return 0;
}
}
