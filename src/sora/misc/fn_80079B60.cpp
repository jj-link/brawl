#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern "C" void fn_801DEF60(void*);
struct Entry { u32 kind; s32 value; s32 other; u32 id; };
struct State {
    char pad[0x340];
    OSMutex mutex;
    char pad2[0x368 - 0x340 - sizeof(OSMutex)];
    Entry entries[150];
    u32 count;
};
extern "C" void fn_80079B60(State* self, u32 id, s32 value) {
    int high = (id >> 8) & 0xff;
    int low = id & 0xff;
    int found = 0;
    OSLockMutex(&self->mutex);
    u8 l = 0;
    for (int i = self->count - 1; i >= 0; --i) {
        u32 current = self->entries[i].id;
        l = current & 0xff;
        int h = (current >> 8) & 0xff;
        if (high == h && l >= low && self->entries[i].kind == 1) {
            for (u32 j = i + 1; j < self->count; ++j) {
                self->entries[j - 1] = self->entries[j];
            }
            --self->count;
            found = 1;
            if (l == low) break;
        }
    }
    if (found) {
        OSUnlockMutex(&self->mutex);
        return;
    }
    if (self->count < 0x95) {
        self->entries[self->count].kind = 2;
        self->entries[self->count].other = -1;
        self->entries[self->count].value = value;
        self->entries[self->count].id = id;
        ++self->count;
    }
    OSUnlockMutex(&self->mutex);
    fn_801DEF60((char*)self + 0x358);
}