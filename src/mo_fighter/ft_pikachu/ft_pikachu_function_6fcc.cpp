#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_98_7028(void*, short);

extern "C" void* fn_98_6FCC(void* object, int deleting) {
    if (object) {
        fn_98_7028(object, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
