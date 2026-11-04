#pragma scheduling off
#pragma optimize_for_size on
#include <so/so_value_accesser.h>
#pragma force_active on

struct Pair { float x, y; };
struct Triple { float x, y, z; };
struct State {
    char pad[0x7c];
    float a, b;
    char pad2[0x84];
    Pair first, second;
    char pad3[8];
    Pair third;
};
extern "C" {
extern const float lbl_103_rodata_14;
extern const float lbl_103_rodata_18;
Triple* fn_103_9594(Triple*, float, float, float);
void fn_27_89D08(int, soModuleAccesser*, int, Pair*, Triple*);
Pair* fn_103_C174(Pair*, const Pair*);
void fn_103_DB98(void*, State* state, void*, soModuleAccesser* accesser) {
    struct Locals {
        bool flag2, flag1;
        Pair secondSpeed, third, second, first, speed;
        Triple rotation2, rotation;
    } locals;
    float x = soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
    if (accesser->m_enumerationStart->m_workManageModule->isFlag(0x22000010) == 1)
        x = soValueAccesser::getConstantFloat(accesser, 0xfaa, 0);
    if (accesser->m_enumerationStart->m_postureModule->getLr() < lbl_103_rodata_14)
        x = -x;
    locals.speed.x = x;
    locals.speed.y = lbl_103_rodata_14;
    fn_27_89D08(3, accesser, 6, &locals.speed,
        fn_103_9594(&locals.rotation, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.flag1 = false;
    locals.first.x = lbl_103_rodata_14;
    locals.first.y = lbl_103_rodata_14;
    fn_103_C174(&state->first, &locals.first);
    locals.second.x = lbl_103_rodata_18;
    locals.second.y = lbl_103_rodata_18;
    fn_103_C174(&state->second, &locals.second);
    locals.third.x = lbl_103_rodata_18;
    locals.third.y = lbl_103_rodata_18;
    fn_103_C174(&state->third, &locals.third);
    float y = soValueAccesser::getConstantFloat(accesser, 0xfab, 0);
    locals.secondSpeed.x = lbl_103_rodata_14;
    locals.secondSpeed.y = y;
    fn_27_89D08(1, accesser, 0, &locals.secondSpeed,
        fn_103_9594(&locals.rotation2, lbl_103_rodata_14, lbl_103_rodata_14, lbl_103_rodata_14));
    locals.flag2 = false;
    state->a = -soValueAccesser::getConstantFloat(accesser, 0xfac, 0);
    state->b = soValueAccesser::getConstantFloat(accesser, 0xfad, 0);
}
}