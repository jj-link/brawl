#include <types.h>
#pragma force_active on

struct Entry {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;
};

struct Owner {
    u8 pad[0x11c];
    u16 count;
    u16 pad2;
    Entry entries[8];

    bool full() const {
        return count >= 8;
    }

    void append(const Entry* src) {
        if (count < 8) {
            entries[count] = *src;
            count++;
        }
    }
};

extern "C" void fn_801251F8(Owner* self, const Entry* src) {
    if (!self->full()) {
        self->append(src);
    }
}
