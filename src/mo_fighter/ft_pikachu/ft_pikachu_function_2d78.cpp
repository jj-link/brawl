#include <new>
#pragma force_active on

extern "C" void* fn_27_19816C(void*, short);

extern "C" void* fn_98_2D78(void* component, short deleting) {
    if (component) {
        fn_27_19816C(component, static_cast<short>(-1));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
