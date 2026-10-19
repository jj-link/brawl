#include <new>
#pragma force_active on

extern "C" void* fn_27_1966BC(void*, short);

extern "C" void* fn_98_2BE4(void* member, int deleting) {
    if (member) {
        fn_27_1966BC(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
