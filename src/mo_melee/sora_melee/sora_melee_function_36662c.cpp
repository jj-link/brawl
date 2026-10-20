#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E847C(void*, int, void*);
extern char lbl_27_data_91808[];
extern char lbl_27_bss_54EC[];

struct fn_27_Obj {
    void* vt0;
    u32 pad4;
    void* vt1;
};

extern "C" fn_27_Obj* fn_27_36662C(fn_27_Obj* self, int del) {
    if (self) {
        self->vt0 = lbl_27_data_91808 + 8;
        self->vt1 = lbl_27_data_91808;
        fn_27_1E847C(self, 0x36, lbl_27_bss_54EC);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
