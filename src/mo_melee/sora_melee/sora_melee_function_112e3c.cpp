#include <types.h>
#pragma force_active on

struct CommonParamFloats {
    u8 unk0[0x4c8];
    float unk4c8;
};

extern "C" void fn_27_112E3C(void** p, float f) {
    ((CommonParamFloats*)*p)->unk4c8 = f;
}
