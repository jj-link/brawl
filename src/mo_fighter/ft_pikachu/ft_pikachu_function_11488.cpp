#include <new>
#pragma force_active on

// Deleting destructor thunk: deletes the object only when the ABI deleting flag is positive (signed 16-bit).
extern "C" void* fn_98_11488(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}
