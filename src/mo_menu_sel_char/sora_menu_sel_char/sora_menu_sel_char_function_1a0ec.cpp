#include <types.h>
#pragma force_active on

extern "C" s32 isTeamBattle__19muSelCharPlayerAreaFv(void*);
extern "C" const u8 lbl_10_rodata_80C[4];
extern "C" const f32 lbl_10_rodata_7D0;

class IFaceObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(f32);
};

extern "C" void fn_10_1A0EC(void* self) {
    u8* base = (u8*)self;
    f32 value;
    if (isTeamBattle__19muSelCharPlayerAreaFv(*(void**)(base + 0x9C))) {
        f32 t = lbl_10_rodata_80C[*(s32*)(*(u8**)(base + 0x9C) + 0x1C0)];
        value = t;
    } else {
        f32 t = *(s32*)(*(u8**)(base + 0x9C) + 0x1B0);
        value = lbl_10_rodata_7D0 + t;
    }
    (*(IFaceObj**)(base + 0x4C))->f5(value);
}
