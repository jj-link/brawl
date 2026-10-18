#include <new>
#pragma force_active on

extern "C" {
void* fn_110_1ACC(void*, short);
void* fn_110_1EAC(void*, short);
void* fn_110_1F48(void*, short);
void* fn_110_2080(void*, short);
void* fn_27_125E20(void*, short);

void* fn_110_1A2C(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_110_1ACC(owner + 0xD240, memberDeleting);
        fn_110_1EAC(owner + 0xCD88, memberDeleting);
        fn_110_1F48(owner + 0xCD4C, memberDeleting);
        fn_110_2080(owner + 0x194, memberDeleting);
        fn_27_125E20(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
