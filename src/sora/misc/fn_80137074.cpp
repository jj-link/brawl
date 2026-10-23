#include <types.h>
#pragma force_active on

struct Entry {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;

    int equals(const Entry& other) const {
        int result = 0;
        if (a == other.a)
            result = 1;
        return result;
    }
};

struct Owner {
    u8 pad[0x7d];
    u8 count;
    u8 pad2[0x174 - 0x7e];
    Entry entries[8];
};

extern "C" int fn_80137074(Owner* self, const Entry* src) {
    u8 count = self->count;
    int result = 0;

    if (count < 8U) {
        for (u32 i = 0; i < count; ++i) {
            if (self->entries[i].equals(*src)) {
                result = 1;
                break;
            }
        }

        if (result == 0) {
            self->entries[count] = *src;
            ++self->count;
            result = 1;
        }
    }

    return result;
}
