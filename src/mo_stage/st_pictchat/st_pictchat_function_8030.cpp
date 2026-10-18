#include <stddef.h>
#pragma force_active on

extern "C" {
    extern char lbl_73_data_3A68[];
    void __dl__FPv(void*);
    void __dla__FPv(void*);
    void fn_73_2CC8(void*, int);
}

extern "C" void* fn_73_8030(void* a, int b) {
    if (a != NULL) {
        if (a != NULL) {
            void* p = *(void**)((char*)a + 0x284);
            *(void**)((char*)a + 0x3c) = lbl_73_data_3A68;
            if (p != NULL) {
                __dl__FPv(p);
            }
            void* q = *(void**)((char*)a + 0x174);
            *(void**)((char*)a + 0x284) = NULL;
            if (q != NULL) {
                __dla__FPv(q);
            }
            *(void**)((char*)a + 0x174) = NULL;
            fn_73_2CC8(a, 0);
        }
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
