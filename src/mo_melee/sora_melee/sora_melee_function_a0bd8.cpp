#include <types.h>
#pragma force_active on

class acAnimCmdConv;

class acCmdInterpreter {
public:
    void resetInterpreter(float, const acAnimCmdConv*);
};

struct fn27Obj {
    u8 pad0[0xFC];
    acCmdInterpreter interp;
    u8 pad1[0x37];
    u32 field134;
    u32 field138;
    u32 field13C;
};

extern "C" const float lbl_27_rodata_CC0;

extern "C" void fn_27_A0BD8(fn27Obj* self, u32 b, u32 c) {
    if (b == self->field134 && c == self->field13C) {
        self->interp.resetInterpreter(lbl_27_rodata_CC0, 0);
        self->field134 = 0;
    }
}
