#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F0;
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_5BD3C(void* self, int flag) {
    if (self) {
        lbl_27_bss_F0 = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
