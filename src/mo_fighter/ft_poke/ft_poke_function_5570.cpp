#pragma force_active on
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_116_3C04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_5570(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<char*>(object) + 0x10, -1);
        fn_116_3C04(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
