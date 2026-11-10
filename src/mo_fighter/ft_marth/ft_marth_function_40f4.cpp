#pragma force_active on
extern "C" {
extern void fn_27_1A2524(void*, short);
extern void __dl__FPv(void*);

void* fn_106_40F4(void* object, short count) {
    if (object != 0) {
        fn_27_1A2524((char*)object + 0x10, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
