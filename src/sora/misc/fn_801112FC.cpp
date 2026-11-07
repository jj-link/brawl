#pragma force_active on
struct Entry { unsigned char pad[8]; unsigned char a, b; short c, d; unsigned char tail[4]; };
struct Obj { unsigned char pad[4]; unsigned short count; unsigned char pad2[14]; Entry* entries; };
extern "C" void fn_801112FC(Obj* self, unsigned short* arg) {
    unsigned short value;
    Entry* entry;
    unsigned int i;
    int offset;
    value = *arg;
    i = 0;
    offset = 0;
    for (; i < self->count; ++i) {
        entry = (Entry*)((char*)self->entries + offset);
        if (entry->a == value) {
            entry->c = -1;
            entry->a = 0;
        }
        if (entry->b == value) {
            entry->d = -1;
            entry->b = 0;
        }
        offset += 18;
    }
}