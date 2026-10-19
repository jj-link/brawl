#include <types.h>
#pragma force_active on

extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_232C(void* object, short deleting) {
    if (object != 0) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
