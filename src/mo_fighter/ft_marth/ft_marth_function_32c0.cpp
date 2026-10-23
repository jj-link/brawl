#pragma force_active on
extern "C" {
extern void fn_27_1A20EC(void*, short);
extern void __dl__FPv(void*);

void* fn_106_32C0(void* object, short count) {
    if (object != 0) {
        fn_27_1A20EC((char*)object + 0x10, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
