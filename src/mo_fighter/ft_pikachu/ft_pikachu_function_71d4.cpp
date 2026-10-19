#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_27_14B698(void*, short);

extern "C" void* fn_98_71D4(void* object, int deleting) {
    if (object) {
        fn_27_14B698(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
