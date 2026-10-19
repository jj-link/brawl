#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_98_394C(void*, short);

extern "C" void* fn_98_38F0(void* accesser, int deleting) {
    if (accesser) {
        fn_98_394C(accesser, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(accesser);
    }
    return accesser;
}
