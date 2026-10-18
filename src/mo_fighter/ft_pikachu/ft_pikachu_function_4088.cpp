#include <new>
#pragma force_active on

extern "C" void* fn_98_1E98(void*, short);

extern "C" void* fn_98_4088(void* object, short deleting) {
    if (object) {
        fn_98_1E98(static_cast<char*>(object) + 8, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
