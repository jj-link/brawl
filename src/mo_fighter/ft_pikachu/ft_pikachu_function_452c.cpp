#include <new>
#pragma force_active on

extern "C" void* fn_27_A1E80(void*, short);

extern "C" void* fn_98_452C(void* object, short deleting) {
    if (object) {
        fn_27_A1E80(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
