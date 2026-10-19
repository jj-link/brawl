#include <types.h>
#pragma force_active on

struct DededeSpeed;

extern "C" void fn_117_D134(DededeSpeed*, const DededeSpeed*);
extern "C" const float lbl_117_rodata_C;

struct DededeZeroPair {
    float x;
    float y;
};

extern "C" void fn_117_D0FC(u8* self) {
    float zeroValue = lbl_117_rodata_C;
    DededeZeroPair zero;
    zero.x = zeroValue;
    zero.y = zeroValue;
    fn_117_D134(reinterpret_cast<DededeSpeed*>(self + 8), reinterpret_cast<const DededeSpeed*>(&zero));
}
