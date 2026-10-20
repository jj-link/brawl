#include <types.h>
#pragma force_active on

struct Entry {
    u8 data[0x30];
};

struct Object {
    u8 padding[8];
    s32 index;
    Entry entries[1];
};

extern "C" void *fn_27_D93E0(Object *object, s32 index)
{
    s32 adjusted = (object->index >> 25) + index;
    if (adjusted < 0x20)
        goto done;
    adjusted -= 0x20;

done:
    return &object->entries[adjusted];
}
