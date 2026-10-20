#include <new>
#pragma force_active on

extern "C" {
void* fn_96_AC10(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_96_9F38(void*, short);

void* fn_96_ACE8(char* self, short deleting) {
    if (self) {
        short memberDeleting = -1;
        fn_96_AC10(self + 0x19464, memberDeleting);
        fn_27_C74E8(self + 0x19454, memberDeleting);
        fn_96_9F38(self, short(0));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
