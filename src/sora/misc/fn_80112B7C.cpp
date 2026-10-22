#include <types.h>
#pragma force_active on

extern "C" void fn_80112674(void*, s32);
extern "C" void fn_80134CA0(void*);
extern char lbl_8049E594[];

extern "C" void fn_80112B7C(void* self) {
    if (((unsigned char*)self)[0x40] >> 7 & 1) {
        if (((unsigned char*)self)[0x41] == 0) {
            fn_80112674(self, 1);
            void* node = *(void**)(lbl_8049E594 + 4);
            void* end = lbl_8049E594 + 4;
            while (node != end) {
                if (((unsigned char*)node)[0x71] >> 7 & 1) {
                    unsigned int w = *(unsigned int*)((char*)node + 0x7C);
                    if ((w >> 24) == 1) {
                        fn_80134CA0(node);
                    }
                }
                node = *(void**)node;
            }
        }
    }
}
