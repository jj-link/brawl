#include <types.h>
#pragma force_active on

extern "C" void* fn_114_232C(void* object, short deleting);
extern "C" void* fn_114_23C8(void* self, short flags);
extern "C" void* fn_114_2408(void* object, short deleting);
extern "C" void* fn_27_C7770(void* self, short flags);

extern "C" void* fn_114_149D4(void* self, short deleting) {
    if (self != 0) {
        fn_114_232C((char*)self + 0xDC, -1);
        fn_114_23C8((char*)self + 0xC0, -1);
        fn_114_2408((char*)self + 0x14, -1);
        if (self != 0) {
            fn_27_C7770(self, -1);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
