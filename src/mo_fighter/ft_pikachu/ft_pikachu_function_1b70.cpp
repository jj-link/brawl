#include <new>
#pragma force_active on

extern "C" {
void fn_98_1AB0(void*, short);
}

extern "C" void* fn_98_1B70(void* component, short deleting) {
    if (component) {
        fn_98_1AB0(component, static_cast<short>(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
