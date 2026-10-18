#include <new>
#pragma force_active on

extern "C" {
void* fn_98_3F10(void*, short);

void* fn_98_138B0(void* object, short deleting) {
    if (object) {
        fn_98_3F10(static_cast<char*>(object) + 0x50, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
