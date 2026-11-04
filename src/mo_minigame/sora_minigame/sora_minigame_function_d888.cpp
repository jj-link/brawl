#include <types.h>
#pragma force_active on

extern "C" void setFrame__16gfModelAnimationFd(void*, double);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void fn_801AF9F4(void*);
extern "C" void fn_20_DA94(void*);
extern "C" const float lbl_20_rodata_398;

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
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
    virtual void v21();
    virtual void v22();
    virtual u32 v23();
};

class Anim {
public:
    virtual void a0();
    virtual void a3(s32, s32, s32);
};

extern "C" void fn_20_D888(Self* self) {
    Anim* anim = *(Anim**)(*(char**)((char*)self + 0x38));
    void* model = *(void**)(*(char**)((char*)self + 0x3C));

    if (anim == 0 || model == 0) {
        return;
    }

    if (*(f32*)((char*)self + 0x24) >= (f32)*(u32*)((char*)self + 0x34) ||
        self->v23() == 1) {
        if (*(f32*)((char*)self + 0x24) > (f32)*(u32*)((char*)self + 0x34)) {
            *(f32*)((char*)self + 0x24) = (f32)*(u32*)((char*)self + 0x34);
        }
        *(u8*)((char*)self + 0x21) = 0;
        *(f32*)((char*)self + 0x30) = lbl_20_rodata_398;
    }

    setFrame__16gfModelAnimationFd(model, *(f32*)((char*)self + 0x24));
    setUpdateRate__16gfModelAnimationFf(model, lbl_20_rodata_398);
    fn_801AF9F4(anim);
    anim->a3(1, 0, 0);
    fn_20_DA94(self);
}
