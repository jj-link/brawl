#include <new>
#pragma force_active on

extern "C" void* fn_98_C108(void*, short);

extern "C" void* fn_98_C168(void* object, short deleting) {
    if (object) {
        fn_98_C108(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
