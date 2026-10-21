#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_94_rodata_C;
extern "C" const float lbl_94_rodata_20;

struct SamusVecObject {
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

extern "C" Vec2f* fn_94_DC68(Vec2f* dst, const Vec2f* src);

extern "C" void fn_94_DC7C(SamusVecObject* object) {
    Vec2f a(lbl_94_rodata_C, lbl_94_rodata_C);
    Vec2f* r = fn_94_DC68(&object->v20, &a);
    r = fn_94_DC68(&object->v10, r);
    fn_94_DC68(&object->v08, r);
    Vec2f b(lbl_94_rodata_20, lbl_94_rodata_20);
    r = fn_94_DC68(&object->v28, &b);
    fn_94_DC68(&object->v18, r);
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
