#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_C9EDC(void*, short);

extern "C" void* fn_98_6EF8(void* self, int deleting) {
    if (self) {
        fn_27_C9EDC(self, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(self);
    }
    return self;
}
