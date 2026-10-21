#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_108_rodata_8;
extern "C" const float lbl_108_rodata_10;

struct FalcoVectorState {
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

extern "C" Vec2f& fn_108_D630(Vec2f& object, const Vec2f& value);

extern "C" void fn_108_D644(FalcoVectorState* object) {
    Vec2f zero(lbl_108_rodata_8, lbl_108_rodata_8);
    fn_108_D630(object->first, fn_108_D630(object->second, fn_108_D630(object->fourth, zero)));
    Vec2f initial(lbl_108_rodata_10, lbl_108_rodata_10);
    fn_108_D630(object->third, fn_108_D630(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
