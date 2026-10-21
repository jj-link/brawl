#include <types.h>
#pragma force_active on

extern "C" void setFrame__16gfModelAnimationFd(void*, double);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void fn_801AF9F4(void*);
extern "C" void fn_27_26EA0C(void*);
extern "C" const float lbl_27_rodata_43A8[];

class grGimmickMotionPath {
public:
    u8 pad[0x3c];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void update();

    void setFrameModelAnim();
};

void grGimmickMotionPath::setFrameModelAnim() {
    void* anim = *(void**)(*(char**)((char*)this + 0x44));
    void* model = *(void**)(*(char**)((char*)this + 0x48));

    if (anim == 0 || model == 0) {
        return;
    }

    setFrame__16gfModelAnimationFd(model, *(float*)((char*)this + 0x150));
    setUpdateRate__16gfModelAnimationFf(model, lbl_27_rodata_43A8[0]);
    fn_801AF9F4(anim);
    *(u8*)((char*)this + 0x6c) &= ~2u;
    update();
    fn_27_26EA0C(this);
}
