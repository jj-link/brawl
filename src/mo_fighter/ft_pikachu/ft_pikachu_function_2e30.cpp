#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_27_ACC5C(void*, short);

extern "C" void* fn_98_2E30(void* member, int deleting) {
    if (member) {
        fn_27_ACC5C(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
