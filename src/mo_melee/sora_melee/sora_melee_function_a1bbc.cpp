#include <types.h>
#pragma force_active on

struct BitField {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" int fn_27_A1BBC(BitField* p) {
    return (int)p->unk8 >> 27;
}
