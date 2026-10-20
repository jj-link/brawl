#include <types.h>
#pragma force_active on

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void fn_114_4854(void*, short);

extern "C" void* fn_114_14FEC(u8* self, short deleteFlag) {
    short memberDeleting = -1;
    if (self != 0) {
        fn_27_13C90(self + 0x9C, memberDeleting);
        fn_27_21038(self + 0x88, memberDeleting);
        fn_114_4854(self, memberDeleting);
        if (deleteFlag > 0) {
            operator delete(self);
        }
    }
    return self;
}
