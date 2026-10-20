#include <types.h>
#pragma force_active on

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

extern "C" {
void* fn_27_6BCF8(void* self, u32 idx) {
    u8* node = (u8*)getNode__6utListFUl((u8*)self + 0x20, 0);
    u32 mask = 1u << idx;
    while (node != 0) {
        u8* data = *(u8**)(node + 0xc);
        if (((*(u32*)(data + 0x30)) >> 8) & mask) {
            u8* acc = (u8*)fn_27_6F30C(node);
            u8* mod = *(u8**)(acc + 0x44);
            return *(void**)(mod + 0x8);
        }
        node = *(u8**)node;
    }
    return 0;
}
}
