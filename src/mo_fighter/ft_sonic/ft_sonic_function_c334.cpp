#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_123_rodata_8;
extern "C" const float lbl_123_rodata_1C;

struct SonicVectorState {
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
extern "C" Vec2f& fn_123_9574(Vec2f& dst, const Vec2f& src);
#pragma dont_inline reset

extern "C" void fn_123_C334(SonicVectorState* object) {
    Vec2f zero(lbl_123_rodata_8, lbl_123_rodata_8);
    fn_123_9574(object->first, fn_123_9574(object->second, fn_123_9574(object->fourth, zero)));
    Vec2f initial(lbl_123_rodata_1C, lbl_123_rodata_1C);
    fn_123_9574(object->third, fn_123_9574(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
