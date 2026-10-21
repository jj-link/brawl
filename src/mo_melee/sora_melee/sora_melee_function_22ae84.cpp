#include <types.h>
#pragma force_active on

struct Value { u32 words[4]; };
struct Entry { u32 key; Value value; };
struct Object { char pad[0x48]; Entry* entries; u32 pad4C; u32 count; };

extern "C" void fn_27_22AF0C(Object*, Entry*, u32, u32*);

extern "C" u32 fn_27_22AE84(Object* self, Entry* entry) {
    u32 index;
    fn_27_22AF0C(self, self->entries, entry->key, &index);
    if (index < self->count) {
        Entry* dst = self->entries;
        dst += index;
        dst->key = entry->key;
        dst->value = entry->value;
    }
    return index;
}
