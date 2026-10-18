#include <new>
#pragma force_active on

extern "C" void* fn_98_C29C(void*, short);

extern "C" void* fn_98_C2FC(void* object, short deleting) {
    if (object) {
        fn_98_C29C(static_cast<char*>(object) + 8, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
