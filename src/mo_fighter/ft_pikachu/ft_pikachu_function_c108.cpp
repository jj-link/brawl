#include <new>
#pragma force_active on

extern "C" void* fn_98_C0AC(void*, short);

extern "C" void* fn_98_C108(void* object, short deleting) {
    if (object) {
        fn_98_C0AC(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
