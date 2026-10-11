#include <so/so_module_accesser.h>

// The ABI deleting flag is interpreted as a signed 16-bit value.
extern "C" void* fn_98_1B294(void* accesser, int deleting) {
    if (accesser && static_cast<short>(deleting) > 0) operator delete(accesser);
    return accesser;
}
