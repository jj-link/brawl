#include <new>
#pragma force_active on

extern "C" void* fn_98_1DD8(void* object, short deleting);

extern "C" void* fn_98_1D7C(void* member, int deleting) {
    if (member) {
        fn_98_1DD8(member, 0);
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
