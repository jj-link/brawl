#include <new>
#pragma force_active on

extern "C" {
void* fn_110_2104(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_110_29BC(void*, short);

void* fn_110_2080(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_110_2104(owner + 0xB54C, memberDeleting);
        fn_27_C74E8(owner + 0xB53C, memberDeleting);
        fn_110_29BC(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
