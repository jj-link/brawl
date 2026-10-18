#include <new>
#pragma force_active on

extern "C" {
void* fn_98_3F10(void*, short);

void* fn_98_5654(void* object, short deleting) {
    if (object) {
        fn_98_3F10(static_cast<char*>(object) + 0x1c0, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
