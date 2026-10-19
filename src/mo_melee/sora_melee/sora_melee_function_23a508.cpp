#include <types.h>
#pragma force_active on

struct SoraMsgStruct {
    /* 0x00 */ u8 pad[0x44];
    /* 0x44 */ u32* field44;
    /* 0x48 */ u8 field48;
    /* 0x49 */ u8 field49;
};

extern "C" void fn_27_23A508(SoraMsgStruct* s, u32* v) {
    *s->field44 = *v;
    s->field49 = 0;
    s->field48 = 1;
}
