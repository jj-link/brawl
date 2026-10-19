#include <stddef.h>
#pragma force_active on

extern "C" void* fn_121_D264(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_121_D3FC(void* object, short deleting) {
    if (object != NULL) {
        fn_121_D264(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
