#include <new>
#pragma force_active on

extern "C" void* fn_27_B64B8(void*, short);

extern "C" void* fn_98_2DD4(void* component, int deleting) {
    if (component) {
        fn_27_B64B8(component, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(component);
    }
    return component;
}
