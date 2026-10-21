#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_119_rodata_1C;
extern "C" const float lbl_119_rodata_30;

struct IkeVectorState {
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
extern "C" Vec2f& fn_119_B6CC(Vec2f& object, const Vec2f& value);
#pragma dont_inline reset

extern "C" void fn_119_B6E0(IkeVectorState* object) {
    Vec2f zero(lbl_119_rodata_1C, lbl_119_rodata_1C);
    fn_119_B6CC(object->first, fn_119_B6CC(object->second, fn_119_B6CC(object->fourth, zero)));
    Vec2f initial(lbl_119_rodata_30, lbl_119_rodata_30);
    fn_119_B6CC(object->third, fn_119_B6CC(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
