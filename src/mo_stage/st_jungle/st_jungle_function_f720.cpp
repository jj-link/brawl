#include <stddef.h>
#include <new>
#pragma force_active on

extern "C" void fn_51_3C30(void*, short);

extern "C" void* fn_51_F720(void* self, int n) {
    if (self != NULL) {
        fn_51_3C30(self, 0);
        if (n > 0) {
            operator delete(self);
        }
    }
    return self;
}
