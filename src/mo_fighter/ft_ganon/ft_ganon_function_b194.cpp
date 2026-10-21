#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_109_rodata_8;
extern "C" const float lbl_109_rodata_C;

extern "C" Vec2f* fn_109_B180(Vec2f* dst, const Vec2f* src);

struct FtGanonVecState {
    u32 header[2];
    Vec2f a8;
    Vec2f a10;
    Vec2f a18;
    Vec2f a20;
    Vec2f a28;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_109_B194(FtGanonVecState* self) {
    Vec2f first(lbl_109_rodata_8, lbl_109_rodata_8);
    fn_109_B180(&self->a8, fn_109_B180(&self->a10, fn_109_B180(&self->a20, &first)));
    Vec2f second(lbl_109_rodata_C, lbl_109_rodata_C);
    fn_109_B180(&self->a18, fn_109_B180(&self->a28, &second));
    self->flag31 = 0;
    self->flag30 = 0;
    self->flag32 = 1;
}
