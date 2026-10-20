#include <types.h>
#pragma force_active on

extern "C" void* fn_27_B5324(void* object, short deleting);
extern "C" void* fn_114_46D8(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_464C(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<char*>(object) + 0x20, -1);

        char* subobject = static_cast<char*>(object) + 0x10;
        if (subobject != 0) {
            fn_114_46D8(subobject, 0);
        }

        if (object != 0) {
            fn_114_46D8(object, 0);
        }

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
