#include <new>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_98_60E0(void*, short);

extern "C" void* fn_98_6068(char* self, short deleting) {
    if (self) {
        fn_27_1A15B8(self + 0x11c, short(-1));
        if (self) fn_98_60E0(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
