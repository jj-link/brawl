#include <stddef.h>
#pragma force_active on

extern "C" void* fn_105_45E4(void* ptr, short size);

extern "C" void* fn_105_78F8(void* object, short baseDeleting) {
    if (object != NULL) {
        fn_105_45E4(object, 0);
        if (baseDeleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
