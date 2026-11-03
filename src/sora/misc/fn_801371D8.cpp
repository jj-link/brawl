#include <types.h>
#pragma force_active on
struct Entry {
    u32 a, b, c;
    u8 d, e;
    int equals(const Entry& other) const {
        int result = 0;
        if (a == other.a) result = 1;
        return result;
    }
};
struct Owner {
    u8 pad[0x7d];
    u8 count;
    u8 pad2[0x174 - 0x7e];
    Entry entries[8];
};
extern "C" void fn_801371D8(Owner* self, const Entry* src) {
    u8 count = self->count;
    for (u32 i = 0; i < count; ++i) {
        if (self->entries[i].equals(*src)) {
            for (; i < self->count - 1; ++i) {
                self->entries[i] = self->entries[i + 1];
            }
            Entry& last = self->entries[self->count - 1];
            last.a = 0;
            last.b = 0;
            last.c = 0;
            last.d = 0;
            --self->count;
            return;
        }
    }
}