#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

extern const float lbl_27_rodata_9A4;

struct Commands {
    const acAnimCmdConv* first;
    const acAnimCmdConv* main;
    const acAnimCmdConv* last;
};

struct Context {
    acCmdInterpreter interpreter;
    char padding[0x10];
    int value;
    const acAnimCmdConv* last;
    int state;
};

extern "C" void fn_27_7022C(Context* self, const Commands* commands, int value, float frame) {
    const acAnimCmdConv* last = self->last;
    self->value = value;
    if (last) {
        self->interpreter.resetInterpreter(lbl_27_rodata_9A4, last);
        self->value = value;
        self->state = 0;
        self->interpreter.interpretCmd(lbl_27_rodata_9A4);
    }
    const acAnimCmdConv* first = commands->first;
    self->last = commands->last;
    if (first) {
        self->interpreter.resetInterpreter(lbl_27_rodata_9A4, first);
        self->value = value;
        self->state = 0;
        self->interpreter.interpretCmd(lbl_27_rodata_9A4);
    }
    self->interpreter.resetInterpreter(frame, commands->main);
}