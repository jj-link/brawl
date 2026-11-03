#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
struct State {
    int active;
    char pad[4];
    short initial;
    char pad2[2];
    unsigned char first;
    char pad3;
    short value;
};
extern "C" void fn_801BA3B8(State* self, float value, float initial) {
    BOOL enabled = OSDisableInterrupts();
    if (!self->active) {
        OSRestoreInterrupts(enabled);
        return;
    }
    BOOL inner = OSDisableInterrupts();
    if (!self->active) {
        OSRestoreInterrupts(inner);
    } else {
        if (self->first) {
            self->first = 0;
            self->initial = (short)(32767.0f * initial);
        }
        self->value = (short)(32767.0f * value);
        OSRestoreInterrupts(inner);
    }
    OSRestoreInterrupts(enabled);
}
