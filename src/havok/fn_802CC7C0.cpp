#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);
extern "C" void fn_802CC72C(void* self, s32 a, s32 b, s32 c);

struct Entry {
    s32 key;
    s32 value;
};

struct Buf {
    char pad[0x1C18];
    Entry* entries;
    s32 count;
    s32 capacity;
};

extern "C" void fn_802CC7C0(Buf* self, s32 key, s32 value) {
    s32 j;
    s32 off;
    s32 i;
    for (i = 0; i < self->count; i++) {
        off = i * 8;
        Entry* e = (Entry*)((char*)self->entries + off);
        if (e->key == key && e->value == value) {
            self->count = self->count - 1;
            j = i;
            while (j < self->count) {
                Entry* base = self->entries;
                *(Entry*)((char*)base + off) = *(Entry*)((char*)base + (j + 1) * 8);
                j++;
                off += 8;
            }
            i--;
        }
    }
    fn_802CC72C(self, key, value, 0);
    if (self->count == (s32)(self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->entries, 8);
    }
    s32 idx = self->count;
    Entry* arr2 = self->entries;
    self->count = idx + 1;
    Entry* e2 = (Entry*)((char*)arr2 + idx * 8);
    e2->key = key;
    e2->value = value;
}
