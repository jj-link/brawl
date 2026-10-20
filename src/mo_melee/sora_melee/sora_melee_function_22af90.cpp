#pragma force_active on
typedef unsigned int u32;
struct Value { u32 words[3]; };
struct Entry { u32 key; Value value; };
struct Object { char pad[0x4C]; Entry* entries; u32 count; };
extern "C" void fn_27_22B010(Object*, Entry*, u32, u32*);
extern "C" u32 fn_27_22AF90(Object* self, Entry* entry) {
    u32 index;
    fn_27_22B010(self, self->entries, entry->key, &index);
    if (index < self->count) {
        Entry* dst = self->entries;
        dst += index;
        dst->key = entry->key;
        dst->value = entry->value;
    }
    return index;
}
