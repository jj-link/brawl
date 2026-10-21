#include <types.h>
#pragma force_active on

extern u8 lbl_80487408[];

struct UnkObj {
    u8* vtable;
    u16 size;
    s16 refs;
    u8 padding[0x28];

    UnkObj() {
        refs = 1;
        vtable = lbl_80487408;
    }
};

extern "C" void* fn_802CEBA4() {
    u8 storage[sizeof(UnkObj)] __attribute__((aligned(16)));
    UnkObj* obj = new (storage) UnkObj;
    return obj->vtable;
}
