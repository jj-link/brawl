#pragma force_active on
extern "C" {
extern void fn_106_3648(void*, short);
extern void __dl__FPv(void*);

void* fn_106_35E8(void* object, short count) {
    if (object != 0) {
        fn_106_3648((char*)object + 0xC, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
