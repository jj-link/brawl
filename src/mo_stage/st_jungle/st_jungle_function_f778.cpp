#pragma force_active on
#include <types.h>

struct Obj {
    char pad[0x4C];
    void* f4C;
    char pad_50[0x1C];
    u8 f6C;
    char pad_6D[0xE7];
    f32 f154;
};

extern "C" {
extern const float lbl_51_rodata_158[4];
void fn_51_3C88(void*);
void fn_801109AC(void*);
void fn_8011097C(void*);
void setEnableCollisionStatus__6GroundFb(void*, bool);

void fn_51_F778(Obj* obj, float arg) {
    const float* c = lbl_51_rodata_158;
    fn_51_3C88(obj);
    obj->f154 = obj->f154 - arg;
    if (obj->f154 < c[1]) {
        obj->f154 = c[0] + obj->f154;
    }
    if (obj->f154 < c[2]) {
        if ((((u32)obj->f6C >> 5) & 1) == 1) {
            setEnableCollisionStatus__6GroundFb(obj, false);
            if (obj->f4C != 0) fn_801109AC(obj->f4C);
        }
    } else {
        if ((((u32)obj->f6C >> 5) & 1) == 0) {
            setEnableCollisionStatus__6GroundFb(obj, true);
            if (obj->f4C != 0) fn_8011097C(obj->f4C);
        }
    }
}
}
