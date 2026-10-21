#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_112_rodata_8;
extern "C" const float lbl_112_rodata_18;

struct PitVectorState {
    u32 header[2];
    Vec2f first;
    Vec2f second;
    Vec2f third;
    Vec2f fourth;
    Vec2f fifth;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

#pragma dont_inline on
extern "C" Vec2f& fn_112_CC3C(Vec2f& object, const Vec2f& value);
#pragma dont_inline reset

extern "C" void fn_112_CC50(PitVectorState* object) {
    Vec2f zero(lbl_112_rodata_8, lbl_112_rodata_8);
    fn_112_CC3C(object->first, fn_112_CC3C(object->second, fn_112_CC3C(object->fourth, zero)));
    Vec2f initial(lbl_112_rodata_18, lbl_112_rodata_18);
    fn_112_CC3C(object->third, fn_112_CC3C(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
