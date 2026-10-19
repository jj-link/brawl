#include <new>
#pragma force_active on

extern "C" {
void fn_27_1A2524(void*, short);
void* fn_98_4480(void*, short);
}

extern "C" void* fn_98_63E4(void* member, short deleting) {
    if (member) {
        fn_27_1A2524(static_cast<char*>(member) + 0x10, -1);
        fn_98_4480(member, 0);
        if (deleting > 0) operator delete(member);
    }
    return member;
}
