#include <types.h>
#pragma force_active on

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void fn_114_4854(void*, short);

struct LucasObject {
    u8 data[0x9C];
};

extern "C" void* fn_114_5A94(void* self, short value) {
    if (self) {
        fn_27_13C90((char*)self + 0x9C, -1);
        fn_27_21038((char*)self + 0x88, -1);
        fn_114_4854(self, -1);
        if (value > 0) {
            delete (LucasObject*)self;
        }
    }
    return self;
}
