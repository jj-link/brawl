#include <mu/mu_object.h>
#pragma force_active on

struct FrameState {
    char pad0[0x100];
    MuObject* object;
    char pad104[0x138];
    int frame;
};

extern "C" void fn_8010C060(FrameState* self) {
    MuObject* object = self->object;
    int frame = self->frame + 1;
    self->frame = frame;
    if (frame == 0x1E) {
        self->frame = 0;
    }
    object->setFrameMatCol((float)self->frame);
}
