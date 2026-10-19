#include <types.h>
#pragma force_active on

extern "C" void fn_41_5D12C(void*, s16);
extern "C" void fn_41_5CF54(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5CFC0(void* self, s16 flag) {
    if (self != nullptr) {
        s16 neg = -1;
        fn_41_5D12C((char*)self + 0x68, neg);
        fn_41_5CF54((char*)self + 4, neg);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
