#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

extern const float lbl_27_rodata_9A4;

extern "C" void fn_27_7030C(acCmdInterpreter* self, const acAnimCmdConv* arg1, s32 arg2, u32 arg3, float farg0) {
    if (arg3 == 1U) {
        const acAnimCmdConv* temp = *(const acAnimCmdConv**)((char*)self + 0x48);
        if (temp != NULL) {
            self->resetInterpreter(lbl_27_rodata_9A4, temp);
            *(s32*)((char*)self + 0x44) = arg2;
            *(s32*)((char*)self + 0x4C) = 0;
            self->interpretCmd(lbl_27_rodata_9A4);
        }
        *(const acAnimCmdConv**)((char*)self + 0x48) = NULL;
    }
    self->resetInterpreter(farg0, arg1);
}
