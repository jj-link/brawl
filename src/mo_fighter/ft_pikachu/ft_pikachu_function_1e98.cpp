#include <new>
#pragma force_active on

extern "C" void fn_27_7700(void*, short);

extern "C" void* fn_98_1E98(void* component, short deleting) {
    if (component) {
        fn_27_7700(component, 0);
        if (deleting > 0) operator delete(component);
    }
    return component;
}
