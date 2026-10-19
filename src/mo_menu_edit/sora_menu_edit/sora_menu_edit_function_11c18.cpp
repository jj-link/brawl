#include <types.h>
#pragma force_active on

extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" void* getBuffer__14gfFileIOHandleCFv(const void*);
extern "C" void fn_5_11C8C(void* self, void* buffer);

struct S {
    u8 pad[0x600];
    u8 loaded;
    u8 pad2[3];
    u8 handle[0x100];
};

extern "C" bool fn_5_11C18(S* self) {
    if (self->loaded == 0) {
        if (!isReady__14gfFileIOHandleCFv(&self->handle[0])) {
            return false;
        }
        fn_5_11C8C(self, getBuffer__14gfFileIOHandleCFv(&self->handle[0]));
        self->loaded = 1;
        return true;
    }
    return true;
}
