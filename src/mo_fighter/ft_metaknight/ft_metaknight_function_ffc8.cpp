#include <types.h>
#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_111_3C4C(void* object, s16 deleting);
void* fn_111_10040(void* object, s16 deleting);
void* fn_27_CD934(void* object, s16 deleting);
}

extern "C" void* fn_111_FFC8(void* object, s16 deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        s16 destroy = -1;
        fn_111_3C4C(storage + 0x8C, destroy);
        fn_111_10040(storage + 0x20, destroy);
        fn_27_CD934(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
