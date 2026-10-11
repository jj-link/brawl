#include <types.h>

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_114_1AF0(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" bool fn_114_C914(void*, s8 kind) {
    const s8 observedKind = 12;
    return kind == observedKind;
}

extern "C" void* fn_114_C930(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x48cb0, -1);
        fn_114_1AF0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
