#pragma force_active on
#include <types.h>
typedef void (*Callback)(void*, void*, int, int, void*);

inline void invoke(u8* self, void* items, u8* data)
{
    Callback callback = *(Callback*)(*(char**)items + self[1] * 0x34 + 0x16AC);
    if (callback)
        callback(self, data, *(int*)(self + 0x14), *(int*)(self + 0x18), items);
}
extern "C" void fn_802FF394(u8* self, void* items)
{
    u8* data;
    switch (self[0]) {
    case 2:
    case 6:
        data = self + 0x20;
        goto call;
    case 4:
        data = self + 0x30;
    call:
        invoke(self, items, data);
        break;
    case 0: break;
    case 1: return;
    case 3: break;
    case 5: break;
    }
}
