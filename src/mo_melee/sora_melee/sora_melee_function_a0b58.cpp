#include <types.h>
#pragma force_active on

class acAnimCmdConv;

class acCmdInterpreter {
public:
    void resetInterpreter(float, const acAnimCmdConv*);
    void interpretCmd(float);
};

struct fn27Obj {
    u8 pad0[0xFC];
    acCmdInterpreter interp;
    u8 pad1[0x134 - 0xFD];
    const acAnimCmdConv* conv134;
    s32 frame138;
    s32 val13C;
};

extern "C" const float lbl_27_rodata_CC0;

extern "C" void fn_27_A0B58(fn27Obj* self, const acAnimCmdConv* conv, s32 frame, s32 val) {
    if (self->conv134 == 0 || self->frame138 <= frame) {
        self->interp.resetInterpreter(lbl_27_rodata_CC0, conv);
        self->interp.interpretCmd(lbl_27_rodata_CC0);
        self->conv134 = conv;
        self->frame138 = frame;
        self->val13C = val;
    }
}
