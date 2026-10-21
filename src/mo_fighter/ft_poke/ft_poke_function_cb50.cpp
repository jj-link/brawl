#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_116_rodata_8;
extern "C" const float lbl_116_rodata_C;

struct FtPokeVectorState {
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
static_assert(sizeof(FtPokeVectorState) == 0x34, "ft_poke vector state layout");

extern "C" Vec2f* fn_116_CB3C(Vec2f*, const Vec2f*);

extern "C" void fn_116_CB50(FtPokeVectorState* object) {
    Vec2f zero(lbl_116_rodata_8, lbl_116_rodata_8);
    fn_116_CB3C(&object->first, fn_116_CB3C(&object->second, fn_116_CB3C(&object->fourth, &zero)));
    Vec2f c(lbl_116_rodata_C, lbl_116_rodata_C);
    fn_116_CB3C(&object->third, fn_116_CB3C(&object->fifth, &c));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
