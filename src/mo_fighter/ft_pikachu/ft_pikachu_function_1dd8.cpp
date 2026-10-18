#include <new>
#pragma force_active on

extern "C" {
// Deletes the object when the ABI deleting flag is positive (read as a signed 16-bit value); returns the object.
void* fn_98_1DD8(void* object, int deleting) {
    if (object && static_cast<short>(deleting) > 0) operator delete(object);
    return object;
}
}
