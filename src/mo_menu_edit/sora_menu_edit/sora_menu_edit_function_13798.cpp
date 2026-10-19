#include <types.h>
#pragma force_active on

struct Entry {
    void* value;
    u32 pad[3];
};

struct Inner {
    u8 pad[0x1a8];
    Entry entries[1];
};

struct Outer {
    u8 pad[0x1ac];
    Inner* inner;
};

extern "C" void* fn_5_13798(Outer* obj, s32 index) {
    return obj->inner->entries[index].value;
}
