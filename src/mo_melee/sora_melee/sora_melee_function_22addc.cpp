#include <types.h>
#pragma force_active on

struct Value { u32 words[8]; };
struct Entry { u32 key; Value value; };
struct Object { char pad[0x44]; Entry* entries; u32 pad48; u32 pad4C; u32 count; };

extern "C" s32 fn_27_22AD58(Object*, Entry*, u32, u32*);

extern "C" u32 fn_27_22ADDC(Object* self, Entry* entry) {
    u32 index;
    fn_27_22AD58(self, self->entries, entry->key, &index);
    if (index < self->count) {
        Entry* dst = self->entries;
        dst += index;
        dst->key = entry->key;
        dst->value = entry->value;
    }
    return index;
}
