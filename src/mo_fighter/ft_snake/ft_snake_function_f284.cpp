#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_122_AA80(void* self, s16 deleteFlag);
void* fn_122_191C(void* object, short deleting);
void __dl__FPv(void*);

void* fn_122_F284(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_C74E8(storage + 0x2d02c, -1);
        fn_122_AA80(storage + 0x2d020, 0);
        fn_122_191C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
