#include <types.h>
#pragma force_active on

struct CleanupStorage {
    u8 padding[0x5C];
};

struct CleanupObject : CleanupStorage {
    virtual ~CleanupObject();
};

struct PeachCleanup {
    u8 padding[0x4C];
    CleanupObject* objects[1];
};

extern "C" void fn_103_10C78(PeachCleanup* self) {
    for (s32 i = 0; i < 1; ++i) {
        if (self->objects[i] != 0) {
            delete self->objects[i];
            self->objects[i] = 0;
        }
    }
}
