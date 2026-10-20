#include <new>
#pragma force_active on

extern "C" {
void* fn_97_8000(void* object, short deleting);
void* fn_27_C74E8(void*, short);
void* fn_97_19D4(void* self, short deleting);

void* fn_97_AE3C(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_97_8000(self + 0x1CD48, memberDeleting);
        fn_27_C74E8(self + 0x1CD34, memberDeleting);
        fn_97_19D4(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
