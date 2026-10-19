#include <new>
#pragma force_active on

extern "C" void* fn_98_4D60(void*, short);

extern "C" void* fn_98_14D3C(void* component, int deleting) {
    if (component) {
        fn_98_4D60(component, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(component);
    }
    return component;
}
