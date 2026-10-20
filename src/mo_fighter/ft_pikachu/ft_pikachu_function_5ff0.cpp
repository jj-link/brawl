#include <new>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_98_6068(void*, short);

extern "C" void* fn_98_5FF0(char* component, short deleting) {
    if (component) {
        fn_27_1A15B8(component + 0x138, short(-1));
        if (component) fn_98_6068(component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
