#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E847C(void* self, int flag, void* extra);
extern "C" void __dl__FPv(void* p);

extern char lbl_27_data_90570[];
extern char lbl_27_bss_54EC[];

struct fn27Obj {
    void* vtbl0;
    int pad4;
    void* vtbl8;
};

extern "C" fn27Obj* fn_27_360230(fn27Obj* self, int shouldFree) {
    if (self) {
        self->vtbl8 = lbl_27_data_90570;
        self->vtbl0 = lbl_27_data_90570 + 8;
        fn_27_1E847C(self, 0x5B, lbl_27_bss_54EC);
        if (shouldFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
