#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E847C(void* self, int id, void* p);
extern "C" void __dl__FPv(void* p);
extern char lbl_27_data_8E0E8[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_351EBC(void* self, int flag) {
    if (self) {
        ((void**)self)[2] = lbl_27_data_8E0E8;
        ((void**)self)[0] = lbl_27_data_8E0E8 + 8;
        fn_27_1E847C(self, 0x75, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
