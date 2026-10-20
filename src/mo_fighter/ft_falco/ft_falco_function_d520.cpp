#pragma force_active on
extern "C" void fn_108_D4C0(void*, short);
extern "C" void fn_108_D38C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_D520(void* object, short deleting) {
    if (object != 0) {
        fn_108_D4C0((char*)object + 0x204, -1);
        if (object != 0) {
            fn_108_D38C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
