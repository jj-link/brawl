#include <types.h>

extern "C" void* fn_114_F54C(void* object, short deleting);
extern "C" void* fn_114_F418(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F5AC(void* object, short deleting) {
    if (object != 0) {
        fn_114_F54C(static_cast<char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_114_F418(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
