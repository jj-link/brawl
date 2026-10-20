#include <new>
#pragma force_active on

extern "C" {
void* fn_108_7ED0(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_108_1978(char*, short);

void* fn_108_ACE0(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_108_7ED0(self + 0x1D094, memberDeleting);
        fn_27_C74E8(self + 0x1D07C, memberDeleting);
        fn_108_1978(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
