#include <so/so_module_accesser.h>
#pragma force_active on

// The ABI deleting flag is interpreted as a signed 16-bit value.
extern "C" void* fn_98_2194(void* accesser, int deleting) {
    if (accesser && static_cast<short>(deleting) > 0) operator delete(accesser);
    return accesser;
}
