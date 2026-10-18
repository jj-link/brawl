#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6880C(void*, short);
void operator delete(void*);

extern "C" void* fn_114_450C(void* object, short deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
