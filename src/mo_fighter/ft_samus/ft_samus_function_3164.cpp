#include <new>
#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void* fn_94_31EC(void*, short);
void* fn_27_CDBBC(void*, short);
void* fn_27_D36DC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_3164(char* self, short param) {
    if (self) {
        short destroy = -1;
        fn_27_93100(self + 0x1D798, destroy);
        fn_94_31EC(self + 0xe0, destroy);
        fn_27_CDBBC(self + 0x34, destroy);
        fn_27_D36DC(self, destroy);
        if (param > 0) operator delete(self);
    }
    return self;
}
