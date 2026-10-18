#include <new>
#pragma force_active on

extern "C" {
void* fn_97_1A74(void*, short);
void* fn_97_1E54(void*, short);
void* fn_97_1EF0(void*, short);
void* fn_97_2028(void*, short);
void fn_27_125E20(void*, short);

void* fn_97_19D4(void* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_97_1A74((char*)self + 0x1CC88, memberDeleting);
        fn_97_1E54((char*)self + 0x1C7D0, memberDeleting);
        fn_97_1EF0((char*)self + 0x1C794, memberDeleting);
        fn_97_2028((char*)self + 0x194, memberDeleting);
        fn_27_125E20(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
