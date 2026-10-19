#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void fn_119_1B44(void*, short);

void* fn_119_1AE8(void* object, short release) {
    if (object != 0) {
        fn_119_1B44(object, (short)0);
        if (release > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
