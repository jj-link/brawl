#include <types.h>
#pragma force_active on

extern "C" void* fn_114_20090(void* object, short deleting);
extern "C" void* fn_114_20350(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_20020(void* object, short deleting) {
    if (object != 0) {
        fn_114_20090(static_cast<char*>(object) + 0x19d4, -1);
        fn_114_20350(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
