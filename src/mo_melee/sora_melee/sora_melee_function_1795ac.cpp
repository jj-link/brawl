#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_value_accesser.h>
#pragma force_active on
struct FrameSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual float frame(); };
struct PostureSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Vec3f position(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual float height(); };
struct ModuleSet { char pad0[0x0C]; PostureSource* posture; char pad10[0x30]; FrameSource* frame; };
struct AccesserLayout { char pad[0xD8]; ModuleSet* modules; };
extern "C" { extern const float lbl_27_data_300E0; extern const float lbl_27_data_300E4; }
extern "C" int fn_27_1795AC(void*, AccesserLayout*, int, int, int*);
extern "C" int fn_27_1795AC(void*, AccesserLayout* accesser, int first, int second, int* out) {
    float current = accesser->modules->frame->frame();
    float duration = accesser->modules->posture->height();
    Vec3f position = accesser->modules->posture->position();
    float y = position.m_y;
    float lower = y;
    float base = y;
    int mode = soValueAccesser::getConstantInt((soModuleAccesser*)accesser, 0x5A99, 0);
    switch (mode) {
    case 0:
        lower = base + lbl_27_data_300E0 * duration;
        base += lbl_27_data_300E4 * duration;
        break;
    case 1:
        lower = base + lbl_27_data_300E4 * duration;
        base = lower;
        break;
    }
    float offset = soValueAccesser::getConstantFloat((soModuleAccesser*)accesser, 0xCBF, 0);
    if (current >= base + offset)
        *out = first;
    else
        *out = second;
    if (current >= lower + offset)
        return 1;
    return 0;
}