#include <stddef.h>
#pragma force_active on

extern "C" {
extern char lbl_40_data_36BC[];
void fn_40_16854(void* p);
void fn_40_168F0(void* p);
void fn_40_16D8C(void* p);
void __dt__6gfTaskFv(void* p, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_17318(char* self, int flags) {
    if (self != NULL) {
        *(void**)(self + 0x3c) = (void*)lbl_40_data_36BC;
        fn_40_16854(self + 0x40);
        fn_40_168F0(self + 0x9c);
        fn_40_16D8C(self + 0xa4);
        __dt__6gfTaskFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
