#include <types.h>
#pragma force_active on

extern "C" void fn_27_93100(void*, short);
extern "C" void fn_114_181BC(void*, short);
extern "C" void fn_27_19F65C(void*, short);
extern "C" void fn_27_1A56B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_18134(void* self, short flag) {
    if (self) {
        short del = -1;
        fn_27_93100((char*)self + 0xBDBC, del);
        fn_114_181BC((char*)self + 0x90, del);
        fn_27_19F65C((char*)self + 0x24, del);
        fn_27_1A56B4(self, del);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
