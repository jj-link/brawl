#include <types.h>

extern "C" void* fn_114_F5AC(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F624(void* object, short deleting) {
    if (object != 0) {
        fn_114_F5AC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
