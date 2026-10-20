#include <types.h>
#pragma force_active on

extern "C" void __dt__10grYakumonoFv(void*, int);
void operator delete(void* p);

extern "C" {
void* fn_27_2726B4(void* self, s32 del) {
    if (self) {
        __dt__10grYakumonoFv(self, 0);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
