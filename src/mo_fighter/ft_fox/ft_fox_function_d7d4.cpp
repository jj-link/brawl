#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_97_rodata_8;
extern "C" const float lbl_97_rodata_10;

struct FoxVectorState {
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
static_assert(sizeof(FoxVectorState) == 0x34, "Fox vector state layout");

extern "C" Vec2f* fn_97_D7C0(Vec2f* dst, const Vec2f* src);

extern "C" void fn_97_D7D4(FoxVectorState* object) {
    Vec2f zero(lbl_97_rodata_8, lbl_97_rodata_8);
    fn_97_D7C0(&object->first, fn_97_D7C0(&object->second, fn_97_D7C0(&object->fourth, &zero)));
    Vec2f initial(lbl_97_rodata_10, lbl_97_rodata_10);
    fn_97_D7C0(&object->third, fn_97_D7C0(&object->fifth, &initial));
    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
