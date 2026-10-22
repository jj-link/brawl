#include <types.h>
#pragma force_active on

extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" u32 getSize__14gfFileIOHandleCFv(const void*);
extern "C" void* getBuffer__14gfFileIOHandleCFv(const void*);
extern "C" void fn_800AD9E0(void* self, void* buffer, u32 size);

struct S {
    u8 pad[0x3EA8];
    u8 loaded;
    u8 pad2[3];
    u8 handle[0x100];
};

extern "C" bool fn_800AD954(S* self) {
    if (self->loaded == 0) {
        if (!isReady__14gfFileIOHandleCFv(&self->handle[0])) {
            return false;
        }
        u32 size = getSize__14gfFileIOHandleCFv(&self->handle[0]);
        void* buffer = getBuffer__14gfFileIOHandleCFv(&self->handle[0]);
        fn_800AD9E0(self, buffer, size);
        self->loaded = 1;
        return true;
    }
    return true;
}
