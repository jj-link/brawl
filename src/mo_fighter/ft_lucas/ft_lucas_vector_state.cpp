#include <mt/mt_vector.h>
#include <types.h>

extern "C" const float lbl_114_rodata_8;
extern "C" const float lbl_114_rodata_18;

struct LucasVectorState {
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
static_assert(sizeof(LucasVectorState) == 0x34, "Lucas vector state layout");

#pragma dont_inline on
extern "C" Vec2f& fn_114_F6BC(Vec2f& object, const Vec2f& value);
#pragma dont_inline reset

extern "C" void fn_114_F684(LucasVectorState* object) {
    Vec2f zero(lbl_114_rodata_8, lbl_114_rodata_8);
    fn_114_F6BC(object->first, zero);
}

#pragma dont_inline on
extern "C" Vec2f& fn_114_F6BC(Vec2f& object, const Vec2f& value) {
    object.m_x = value.m_x;
    object.m_y = value.m_y;
    return object;
}
#pragma dont_inline reset

extern "C" void fn_114_F6D0(LucasVectorState* object) {
    Vec2f zero(lbl_114_rodata_8, lbl_114_rodata_8);
    fn_114_F6BC(object->first, fn_114_F6BC(object->second, fn_114_F6BC(object->fourth, zero)));
    Vec2f initial(lbl_114_rodata_18, lbl_114_rodata_18);
    fn_114_F6BC(object->third, fn_114_F6BC(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}

extern "C" void fn_114_F768(LucasVectorState* object) {
    object->flag31 = 0;
}

extern "C" void fn_114_F774(LucasVectorState* object) {
    object->flag31 = 1;
}

extern "C" void fn_114_F780(Vec3f* object) {
    object->m_x = lbl_114_rodata_8;
    object->m_y = lbl_114_rodata_8;
    object->m_z = lbl_114_rodata_8;
}

extern "C" Vec2f fn_114_F798(const LucasVectorState* object) {
    return object->first;
}
