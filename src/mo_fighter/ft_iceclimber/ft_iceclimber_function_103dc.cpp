#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_105_rodata_10;
extern "C" const float lbl_105_rodata_30;

struct IceClimberVecState {
    u8 pad0[0x08];
    Vec2f c08;
    Vec2f c10;
    Vec2f c18;
    Vec2f c20;
    Vec2f c28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" Vec2f& fn_105_103C8(Vec2f& dst, const Vec2f& src);

extern "C" void fn_105_103DC(IceClimberVecState* object) {
    Vec2f a(lbl_105_rodata_10, lbl_105_rodata_10);
    fn_105_103C8(object->c08, fn_105_103C8(object->c10, fn_105_103C8(object->c20, a)));
    Vec2f b(lbl_105_rodata_30, lbl_105_rodata_30);
    fn_105_103C8(object->c18, fn_105_103C8(object->c28, b));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
