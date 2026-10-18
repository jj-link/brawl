#include <so/so_module_accesser.h>
#pragma force_active on

// The ABI deleting flag is interpreted as a signed 16-bit value.
extern "C" void* fn_98_3F6C(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}
