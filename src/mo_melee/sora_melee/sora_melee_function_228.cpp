#include <types.h>
#pragma force_active on
struct Vec3 { float x, y, z; };
struct Class_50_base {
    char pad0[0x10];
    Vec3 pos;
    char pad1[4];
    float distance;
    char pad2;
    u8 kind;
    char pad3[0xa];
};
class Class_50 : public Class_50_base {
public:
    virtual void fn_27_1C28();
    virtual void fn_27_2A9C();
    virtual void fn_27_1C80();
    virtual void fn_27_1D70();
    virtual Vec3 fn_27_2678();
};
struct Class_A0_base { char pad[0x30]; };
class Class_A0 : public Class_A0_base {
public:
    virtual void fn_27_2AE0();
    virtual void fn_27_3624();
    virtual void fn_27_2B38();
    virtual void fn_27_2B70();
    virtual Vec3 fn_27_3354();
};
extern "C" const float lbl_27_rodata_0;
extern "C" int fn_27_228(Class_50* a, Class_50* b) {
    if (a->kind == 1 || b->kind == 1) {
        if (a->kind == 1) {
            a->pos = b->fn_27_2678();
        } else {
            a->pos = a->fn_27_2678();
        }
        b->pos = a->pos;
        a->distance = lbl_27_rodata_0;
        b->distance = lbl_27_rodata_0;
        return 1;
    }
    return 0;
}