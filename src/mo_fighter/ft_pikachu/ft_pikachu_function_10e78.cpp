#include <new>
#pragma force_active on

extern "C" void* fn_98_10E78(void* object, short deleting) {
    if (object && deleting > 0) operator delete(object);
    return object;
}
