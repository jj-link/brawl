#include <types.h>
#pragma force_active on

extern "C" void fn_41_60968(void*, short);
extern "C" void fn_41_60658(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_606B8(void* self, short param) {
    if (self != nullptr) {
        fn_41_60968((char*)self + 0x38, -1);
        fn_41_60658((char*)self + 4, -1);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
