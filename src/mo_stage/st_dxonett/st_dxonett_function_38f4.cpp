#include <stddef.h>
#pragma force_active on

struct StObj {
    unsigned char pad0[0x3C];
    void* vtbl;
    unsigned char pad1[0x168 - 0x40];
    void* ptr168;
};

extern "C" {
    extern char lbl_78_data_1390[];
    void fn_78_17D0(StObj* self, int arg);
}

extern "C" StObj* fn_78_38F4(StObj* self, int flags) {
    if (self != NULL) {
        void* p = self->ptr168;
        self->vtbl = lbl_78_data_1390;
        if (p != NULL) {
            operator delete(p);
        }
        self->ptr168 = NULL;
        fn_78_17D0(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
