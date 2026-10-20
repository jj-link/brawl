#include <new>
#pragma force_active on

extern "C" {
void* fn_27_1A1CFC(void*, short);
void* fn_98_5A50(void*, short);
}

extern "C" void* fn_98_59D8(char* component, short deleting) {
    if (component) {
        fn_27_1A1CFC(component + 0x524, short(-1));
        if (component) fn_98_5A50(component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
