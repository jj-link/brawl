#include <types.h>
#pragma force_active on

extern "C" void fn_27_C9EDC(void* self, short param);

#pragma dont_inline on
extern "C" void* fn_111_59E4(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C9EDC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
