#include <new>
#pragma force_active on

extern "C" void* fn_27_A0C34(void*, short);

extern "C" void* fn_98_308C(void* self, int deleting) {
    if (self) {
        fn_27_A0C34(self, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(self);
    }
    return self;
}
