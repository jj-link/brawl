#include <types.h>
#pragma force_active on

struct Vec2f {
    float m_x;
    float m_y;
};

struct WolfVec2State {
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

extern "C" const float lbl_125_rodata_8;
extern "C" const float lbl_125_rodata_10;
extern "C" Vec2f* fn_125_D6D8(Vec2f* dst, const Vec2f* src);

extern "C" void fn_125_D6EC(WolfVec2State* object) {
    Vec2f zero;
    zero.m_x = lbl_125_rodata_8;
    zero.m_y = lbl_125_rodata_8;
    fn_125_D6D8(&object->first, fn_125_D6D8(&object->second, fn_125_D6D8(&object->fourth, &zero)));
    Vec2f initial;
    initial.m_x = lbl_125_rodata_10;
    initial.m_y = lbl_125_rodata_10;
    fn_125_D6D8(&object->third, fn_125_D6D8(&object->fifth, &initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
