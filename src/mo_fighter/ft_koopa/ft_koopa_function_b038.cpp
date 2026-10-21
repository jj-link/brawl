#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_102_rodata_8;
extern "C" const float lbl_102_rodata_C;
extern "C" Vec2f* fn_102_B024(Vec2f* dst, const Vec2f* src);

struct KoopaVec2State {
    u32 header[2];
    Vec2f v8;
    Vec2f v10;
    Vec2f v18;
    Vec2f v20;
    Vec2f v28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_102_B038(KoopaVec2State* object) {
    Vec2f zero(lbl_102_rodata_8, lbl_102_rodata_8);
    Vec2f* r = fn_102_B024(&object->v20, &zero);
    r = fn_102_B024(&object->v10, r);
    fn_102_B024(&object->v8, r);
    Vec2f one(lbl_102_rodata_C, lbl_102_rodata_C);
    r = fn_102_B024(&object->v28, &one);
    fn_102_B024(&object->v18, r);
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
