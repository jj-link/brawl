#include <types.h>

extern "C" void* fn_114_F624(void* member, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_D288(void* object, short deleting) {
    if (object != 0) {
        fn_114_F624(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
