#include <new>
#pragma force_active on

extern "C" {
void* fn_119_2068(void*, short);
void* fn_27_C74E8(void*, short);
void fn_119_2920(void*, short);

void* fn_119_1FE4(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_119_2068(self + 0x8E1C, memberDeleting);
        fn_27_C74E8(self + 0x8E0C, memberDeleting);
        fn_119_2920(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
