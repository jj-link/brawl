#include <types.h>
#pragma force_active on

extern "C" void fn_80134CA0(void*);
extern "C" void fn_80110CEC(void*);
extern "C" void fn_80110F7C(void*);
extern char lbl_8049E594[];

extern "C" void fn_80112AD4(void* self) {
    if (((unsigned char*)self)[0x40] >> 7 & 1) {
        if (((unsigned char*)self)[0x41] == 0) {
            void* node = *(void**)(lbl_8049E594 + 4);
            void* end = lbl_8049E594 + 4;
            while (node != end) {
                if (((unsigned char*)node)[0x71] >> 7 & 1) {
                    unsigned int w = *(unsigned int*)((char*)node + 0x7C);
                    if ((w >> 24) == 0) {
                        fn_80134CA0(node);
                        void* r29 = *(void**)((char*)node + 0x68);
                        if (r29 != 0) {
                            fn_80110CEC(r29);
                            fn_80110F7C(r29);
                        }
                    }
                }
                node = *(void**)node;
            }
        }
    }
}
