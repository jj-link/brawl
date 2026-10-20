#include <types.h>
#pragma force_active on

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" void* fn_27_6F30C(void*);

extern "C" void* fn_27_6BD6C(void* self, u32 id) {
    u8* node = (u8*)getNode__6utListFUl((u8*)self + 0x14, 0);
    while (node != 0) {
        if (id == *(u32*)(node + 0x8)) {
            node = (u8*)fn_27_6F30C(node);
            return *(void**)(*(u8**)(node + 0x44) + 0x8);
        }
        node = *(u8**)node;
    }
    return 0;
}
