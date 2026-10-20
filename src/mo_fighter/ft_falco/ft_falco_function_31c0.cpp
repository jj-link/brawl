#include <types.h>
#pragma force_active on

extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_108_3248(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_31C0(void* self, s32 p2) {
    if (self != 0) {
        short destroy = -1;
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_93100(storage + 0x15004, destroy);
        fn_108_3248(storage + 0x7c, destroy);
        fn_27_19F4C4(storage + 0x20, destroy);
        fn_27_1A55B0(self, destroy);
        if ((s16)p2 > 0) __dl__FPv(self);
    }
    return self;
}
