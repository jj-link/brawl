#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_122_rodata_C;
extern "C" const float lbl_122_rodata_1C;

extern "C" Vec2f* fn_122_12CC4(Vec2f* dst, const Vec2f* src);

extern "C" void fn_122_12CD8(char* object) {
    Vec2f zero(lbl_122_rodata_C, lbl_122_rodata_C);
    Vec2f* p = fn_122_12CC4((Vec2f*)(object + 0x20), &zero);
    p = fn_122_12CC4((Vec2f*)(object + 0x10), p);
    fn_122_12CC4((Vec2f*)(object + 0x8), p);

    Vec2f one(lbl_122_rodata_1C, lbl_122_rodata_1C);
    p = fn_122_12CC4((Vec2f*)(object + 0x28), &one);
    fn_122_12CC4((Vec2f*)(object + 0x18), p);

    *(u8*)(object + 0x31) = 0;
    *(u8*)(object + 0x30) = 0;
    *(u8*)(object + 0x32) = 1;
}
