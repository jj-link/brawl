#include <types.h>
#pragma force_active on

#pragma opt_loop_invariants off
extern "C" void* fn_8015C1B0(void*, void*);

extern "C" void fn_80166CE8(void* arg0) {
    *(u8*)((char*)arg0 + 0x104) = 1;
    for (void* node = 0; (node = fn_8015C1B0((char*)arg0 + 0xc0, node)) != 0;) {
        *(u8*)((char*)node + 0x8a) = 1;
    }
    if (*(void**)((char*)arg0 + 0xbc) != 0) {
        for (void* node2 = 0; (node2 = fn_8015C1B0(*(char**)((char*)arg0 + 0xbc) + 0x24, node2)) != 0;) {
            if (*(u8*)((char*)node2 + 0x104) == 0) {
                for (void* p = *(void**)((char*)node2 + 0xf4); p != 0; p = *(void**)((char*)p + 0xf4)) {
                    if (p == arg0) {
                        *(u8*)((char*)node2 + 0x104) = 1;
                        for (void* node3 = 0; (node3 = fn_8015C1B0((char*)node2 + 0xc0, node3)) != 0;) {
                            *(u8*)((char*)node3 + 0x8a) = 1;
                        }
                    }
                }
            }
        }
    }
}
