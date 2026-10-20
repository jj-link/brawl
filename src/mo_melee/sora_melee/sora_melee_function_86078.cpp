#include <types.h>
#pragma force_active on

extern signed char lbl_27_bss_1898;
extern char lbl_27_bss_189C[];
extern char lbl_27_bss_101C[];

extern "C" {
void __ct__18soModelVirtualNodeFv(void*);
void __dt__18soModelVirtualNodeFv(void*, int);
int __register_global_object(void*, void*, void*);
}

extern "C" void* fn_27_86078() {
    if (lbl_27_bss_1898 == 0) {
        __ct__18soModelVirtualNodeFv(lbl_27_bss_189C);
        __register_global_object(lbl_27_bss_189C, (void*)__dt__18soModelVirtualNodeFv, lbl_27_bss_101C);
        lbl_27_bss_1898 = 1;
    }
    return lbl_27_bss_189C;
}
