#pragma force_active on
extern "C" {
extern void fn_27_1A2B08(void*, short);
extern void __dl__FPv(void*);

void* fn_106_34B4(void* object, short count) {
    if (object != 0) {
        fn_27_1A2B08((char*)object + 4, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}