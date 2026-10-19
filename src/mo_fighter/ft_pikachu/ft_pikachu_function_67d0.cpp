#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_27_66114(void*, short);

extern "C" void* fn_98_67D0(void* ptr, int deleting) {
    if (ptr) {
        fn_27_66114(ptr, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(ptr);
    }
    return ptr;
}
