#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_27_19874C(void*, short);

extern "C" void* fn_98_30E8(void* member, int deleting) {
    if (member) {
        fn_27_19874C(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
