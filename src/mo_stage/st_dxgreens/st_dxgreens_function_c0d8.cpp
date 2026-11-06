#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
bool getPlayerPosition__7stMeleeFiP5Vec3f(int, Vec3f*);
float randf__Fv();
}

extern const float lbl_79_rodata_60;
extern const float lbl_79_rodata_64;

extern "C" u32 fn_79_C0D8() {
    Vec3f pos;
    f32 threshold = lbl_79_rodata_60;
    u32 i = 0;
    u8 negative = 0;
    u8 positive = 0;
    for (i = 0; i < 4; i++) {
        if (getPlayerPosition__7stMeleeFiP5Vec3f((u8)i, &pos) == true) {
            if (pos.m_x > threshold) {
                positive++;
            }
            if (pos.m_x < threshold) {
                negative++;
            }
        }
    }
    if (negative == positive) {
        return (randf__Fv() < lbl_79_rodata_64) == 0;
    }
    return (u32)(positive - negative) >> 31;
}
