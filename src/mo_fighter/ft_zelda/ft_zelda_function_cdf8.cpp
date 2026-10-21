#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_104_rodata_8;
extern "C" const float lbl_104_rodata_10;

struct ZeldaVectorState {
    u32 header[2];
    Vec2f v08;
    Vec2f v10;
    Vec2f v18;
    Vec2f v20;
    Vec2f v28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" Vec2f* fn_104_CDE4(Vec2f* dst, const Vec2f* src);

extern "C" void fn_104_CDF8(ZeldaVectorState* object) {
    Vec2f a(lbl_104_rodata_8, lbl_104_rodata_8);
    Vec2f* p = fn_104_CDE4(&object->v20, &a);
    p = fn_104_CDE4(&object->v10, p);
    fn_104_CDE4(&object->v08, p);
    Vec2f b(lbl_104_rodata_10, lbl_104_rodata_10);
    p = fn_104_CDE4(&object->v28, &b);
    fn_104_CDE4(&object->v18, p);
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
