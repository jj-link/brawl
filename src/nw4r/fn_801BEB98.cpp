#include <stddef.h>
#pragma force_active on

extern "C" {
extern char lbl_804666B8[];
void fn_801F6524(void* self, void* vt);
void fn_801C6B94(void* self);
void fn_801C6B38(void* self, int destroy);
void __dl__FPv(void* p);
}

extern "C" void* fn_801BEB98(char* self, int flags) {
    if (self != NULL) {
        *(void**)self = (void*)lbl_804666B8;
        fn_801F6524(self + 0x14c, (void*)lbl_804666B8);
        self[0x188] = 0;
        fn_801C6B94(self);
        fn_801C6B38(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
