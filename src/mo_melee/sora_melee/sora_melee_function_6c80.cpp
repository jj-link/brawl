#include <types.h>
#pragma force_active on

extern "C" extern const float lbl_27_rodata_7C;

typedef union {
    float f;
    u32 i;
} FloatBits;

typedef struct {
    FloatBits a;
    FloatBits b;
} FloatPair;

extern "C" FloatPair fn_27_6C80(void)
{
    FloatPair p;
    p.a.f = lbl_27_rodata_7C;
    p.b.f = lbl_27_rodata_7C;
    return p;
}
