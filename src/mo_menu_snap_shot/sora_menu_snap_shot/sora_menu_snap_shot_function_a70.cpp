#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_800C2BB4(void*, int);
void fn_6_930(void*, int);
void __dl__FPv(void*);

void* fn_8_A70(void* a, int b) {
    if (a != NULL) {
        void* p = (void*)((char*)a + 0x1d14);
        if (p != NULL) {
            if (p != NULL) {
                fn_800C2BB4(p, 0);
            }
        }
        fn_6_930(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}
