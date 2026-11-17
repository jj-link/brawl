#include <types.h>
#pragma force_active on
extern "C" void fn_8027CE3C(void*, int);
struct Entry { u8 key; void* id; s32 val; };
struct Array { Entry* data; s32 count; u32 cap; };
struct Table { Array arr; u8 pad[0x60]; s32 counter; };
static inline void add(Array* self, const Entry& value) {
    if (self->count == (s32)(self->cap & 0x3FFFFFFF))
        fn_8027CE3C(self, 12);
    self->data[self->count++] = value;
}
extern "C" s32 fn_8008653C(Table* self, void* arg1, u8* arg2) {
    for (s32 i = 0; i < *(s32*)((char*)self + 4); i++) {
        if (self->arr.data[i].id == arg1)
            return -1;
    }
    Entry value;
    value.key = *arg2;
    value.id = arg1;
    value.val = self->counter;
    add(&self->arr, value);
    return self->counter++;
}
