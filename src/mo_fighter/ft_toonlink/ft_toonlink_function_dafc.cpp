#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_121_rodata_C;
extern "C" const float lbl_121_rodata_18;

struct ToonLinkVectorState {
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
static_assert(sizeof(ToonLinkVectorState) == 0x34, "Toon Link vector state layout");

#pragma dont_inline on
extern "C" Vec2f& fn_121_DAE8(Vec2f& object, const Vec2f& value);
#pragma dont_inline reset

extern "C" void fn_121_DAFC(ToonLinkVectorState* object) {
    Vec2f zero(lbl_121_rodata_C, lbl_121_rodata_C);
    fn_121_DAE8(object->first, fn_121_DAE8(object->second, fn_121_DAE8(object->fourth, zero)));
    Vec2f initial(lbl_121_rodata_18, lbl_121_rodata_18);
    fn_121_DAE8(object->third, fn_121_DAE8(object->fifth, initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
