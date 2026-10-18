#include <new>
#pragma force_active on

// Deletes the object when the ABI deleting flag is positive (signed 16-bit), then returns it.
extern "C" void* fn_98_FFE0(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}
