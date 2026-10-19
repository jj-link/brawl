#include <types.h>
#pragma force_active on

extern "C" void* __dt__16acCmdInterpreterFv(void*, short);

#pragma dont_inline on
extern "C" void* fn_111_20E8(void* object, s16 deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
