#include <new>
#pragma force_active on

extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_98_4048(void*, short);

extern "C" void* fn_98_572C(char* component, short deleting) {
    if (component) {
        fn_27_1A20EC(component + 0x10, short(-1));
        fn_98_4048(component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
