#include <new>
#pragma force_active on

extern "C" void* fn_27_5C674(void*, short);

extern "C" void* fn_98_3C10(void* object, int deleting) {
    if (object) {
        fn_27_5C674(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
