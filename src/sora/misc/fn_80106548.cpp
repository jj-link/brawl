#include <types.h>
#pragma force_active on

struct Entry {
    char pad[0x14];
    s32 handle;
};

struct Container {
    s32 unk0;
    s32 count;
    char* base;
    s32 index;
};

extern "C" {
bool isReady__14gfFileIOHandleCFv(const void* self);
bool isCanceled__14gfFileIOHandleCFv(const void* self);

s32 fn_80106548(Container* arg0) {
    s32 i = 0;
    while (i < arg0->count) {
        Entry* e = (Entry*)(arg0->base + arg0->index * 0xA0);
        if (e->handle != 0) {
            if (!isReady__14gfFileIOHandleCFv(&e->handle) && !isCanceled__14gfFileIOHandleCFv(&e->handle)) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}
}
