#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_27_14FCF4(void*, short);

extern "C" void* fn_98_2F98(void* component, int deleting) {
    if (component) {
        fn_27_14FCF4(component, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(component);
    }
    return component;
}
