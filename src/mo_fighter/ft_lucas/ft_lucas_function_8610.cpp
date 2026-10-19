#include <types.h>
#pragma force_active on

extern "C" void fn_27_C96C0(void*, short);
void operator delete(void*);

extern "C" void* fn_114_8610(void* self, short deleting) {
    if (self != 0) {
        fn_27_C96C0(self, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
