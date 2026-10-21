#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_8;
extern "C" const float lbl_96_rodata_20;

extern "C" Vec2f* fn_96_B890(Vec2f* dst, const Vec2f* src);

struct KirbyVectorState {
    u8 pad0[8];
    Vec2f v8;
    Vec2f v10;
    Vec2f v18;
    Vec2f v20;
    Vec2f v28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_96_1256C(KirbyVectorState* object) {
    Vec2f zero(lbl_96_rodata_8, lbl_96_rodata_8);
    fn_96_B890(&object->v8, fn_96_B890(&object->v10, fn_96_B890(&object->v20, &zero)));
    Vec2f initial(lbl_96_rodata_20, lbl_96_rodata_20);
    fn_96_B890(&object->v18, fn_96_B890(&object->v28, &initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
