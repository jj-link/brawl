#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7D010[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int a, void* b);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_2E4E9C(void* self, int flag) {
    if (self) {
        void** p = (void**)self;
        p[2] = lbl_27_data_7D010;
        p[0] = lbl_27_data_7D010 + 8;
        fn_27_1E847C(self, 5, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
