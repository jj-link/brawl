#include <stddef.h>
#pragma force_active on

struct FZeroObject;

extern "C" {
void fn_61_2384(FZeroObject* self, int flag);
void __dl__FPv(void* p);
}

extern "C" FZeroObject* fn_61_5E4C(FZeroObject* self, int del) {
    if (self != NULL) {
        fn_61_2384(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
