#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3AA0(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_114_17F0C(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_17E7C(char* self, short deleting) {
    if (self != 0) {
        fn_114_3AA0(self + 0xDD8C, -1);
        fn_27_1DBB60(self + 0xDD54, -1);
        fn_114_17F0C(self + 0xCC, -1);
        fn_27_1D81C8(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
