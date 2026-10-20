#include <types.h>
#pragma force_active on

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

extern "C" void* fn_27_6BC94(u8* self, u32 id) {
    u8* node = (u8*)getNode__6utListFUl(self + 0x20, 0);
    while (node != 0) {
        if (id == *(u32*)(node + 0x8)) {
            u8* acc = (u8*)fn_27_6F30C(node);
            return *(void**)(*(u8**)(acc + 0x44) + 0x8);
        }
        node = *(u8**)node;
    }
    return 0;
}
