#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_C96C0(void*, short);

extern "C" void* fn_98_6E9C(void* object, int deleting) {
    if (object) {
        fn_27_C96C0(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
