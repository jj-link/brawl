#include <new>
#pragma force_active on

extern "C" {
void fn_112_44C0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_112_14DF0(void*, short);
void* fn_27_1D81C8(void*, short);

void* fn_112_14D60(char* self, short deleting) {
    if (self) {
        char* p = self + 0x20000;
        fn_112_44C0(p - 0x7FF4, -1);
        fn_27_1DBB60(self + 0x10000 + 0x7FD4, -1);
        fn_112_14DF0(self + 0xCC, -1);
        fn_27_1D81C8(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
