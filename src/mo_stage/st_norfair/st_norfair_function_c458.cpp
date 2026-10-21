#include <types.h>
#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);
struct Entry { float x,y,z; };
inline void copyEntry(Entry* dst, const Entry* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
extern "C" void fn_54_C458(void* self) {
    u8* p = (u8*)self;
    u8* base = p + 0xd0;
    if (base != 0) {
        u8* model = *(u8**)(*(u8**)(p + 0x44));
        if (model != 0) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(base + 0xc) = 0;
                *(u8**)(model + 0x11c) = base;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(base + 4);
            }
            Entry* entries = *(Entry**)(p + 0x15c);
            if (entries != 0) {
                copyEntry((Entry*)(*(u8**)(base + 4) + 8), &entries[**(u8**)(p + 0x160)]);
            }
        }
    }
}
