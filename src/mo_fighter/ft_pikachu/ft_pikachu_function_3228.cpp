#include <new>
#pragma force_active on

extern "C" {
void* fn_98_3298(char*, short);
void* fn_98_4D60(void*, short);
}

extern "C" void* fn_98_3228(char* component, short deleting) {
    if (component) {
        fn_98_3298(component + 0x8, short(-1));
        fn_98_4D60(component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
