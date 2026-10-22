#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);

struct Entry {
    s32 key;
    s32 value;
};

struct Buf {
    char pad[0x30];
    Entry* entries;
    s32 count;
    s32 capacity;
};

extern "C" void fn_8033249C(Buf* self, s32 key, s32 value) {
    if (self->count == (s32)(self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->entries, 8);
    }
    s32 idx = self->count;
    Entry* arr = self->entries;
    self->count = idx + 1;
    Entry* e = (Entry*)((char*)arr + idx * 8);
    e->key = key;
    e->value = value;
}
