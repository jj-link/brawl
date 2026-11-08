#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_3C4;

extern "C" Vec2f fn_27_28150(soGroundModule* self, int index, int arg2) {
    switch (index) {
    case 1:
        return self->getUpPos(arg2);
    case 8:
        return self->getDownPos(arg2);
    case 2:
        return self->getLeftPos(arg2);
    case 4:
        return self->getRightPos(arg2);
    default:
        return Vec2f(lbl_27_rodata_3C4, lbl_27_rodata_3C4);
    }
}
