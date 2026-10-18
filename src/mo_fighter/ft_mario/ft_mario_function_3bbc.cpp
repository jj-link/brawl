#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void* fn_91_3BBC(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
}
