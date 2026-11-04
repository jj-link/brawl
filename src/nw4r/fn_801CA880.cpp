#include <stddef.h>
#pragma force_active on

extern "C" {
extern char lbl_80466BD8[];
void fn_801BF96C(void*);
void fn_801BF6BC(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_801CA880(char* self, int flags) {
    if (self != NULL) {
        *(void**)self = lbl_80466BD8;
        fn_801BF96C(self + 0x1c);
        fn_801BF6BC(self + 0x1c, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}