#include <types.h>
#pragma force_active on

extern "C" void fn_41_28F74(void*, u32, u32);
extern "C" void fn_41_B8D4(void*, void*, void*, void*, void*);

extern "C" void fn_41_630CC(u8* self, u8* p2, void* p3, void* p4, void* p5) {
    switch (*(s32*)p2) {
    case 0x13FF:
        fn_41_28F74(self + 0x1108, 1, 0x13);
        p2[4] = 1;
        break;
    }
    fn_41_B8D4(self, p2, p3, p4, p5);
}
