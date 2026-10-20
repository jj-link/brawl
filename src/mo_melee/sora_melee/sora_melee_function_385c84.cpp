#include <types.h>
#pragma force_active on

extern "C" void fn_27_385C84(void* self, unsigned int bits) {
    struct Obj {
        unsigned char pad[8];
        unsigned int value : 3;
    };
    static_cast<Obj*>(self)->value = bits;
}
