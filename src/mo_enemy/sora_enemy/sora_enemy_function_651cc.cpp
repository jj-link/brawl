#include <cstddef>
#pragma force_active on

extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_65160(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_651CC(void* self, short p1) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x1B8, -1);
        fn_41_65160(static_cast<char*>(self) + 4, -1);
        if (p1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
