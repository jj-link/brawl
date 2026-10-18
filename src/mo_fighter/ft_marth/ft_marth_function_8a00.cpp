#pragma force_active on
extern "C" {
typedef signed short s16;

extern void fn_106_89A4(void*, s16);
extern void __dl__FPv(void*);

void* fn_106_8A00(void* object, s16 should_delete) {
    if (object != 0) {
        fn_106_89A4((char*)object + 4, (s16)-1);
        if (should_delete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
