#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_116_5A74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_59FC(void* object, int deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_116_5A74(object, 0);
        }
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
