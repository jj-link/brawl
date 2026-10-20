#include <new>
#pragma force_active on

extern "C" void* fn_98_3580(void* object, short deleting);
extern "C" void* fn_98_4F04(char* object, short deleting);

extern "C" void* fn_98_3508(void* component, short deleting) {
    if (component) {
        fn_98_3580((char*)component + 0x7f40, short(-1));
        if (component)
            fn_98_4F04((char*)component, short(0));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
