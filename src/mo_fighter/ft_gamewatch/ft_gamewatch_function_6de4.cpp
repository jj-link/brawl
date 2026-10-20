#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_107_6E5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_6DE4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, static_cast<short>(-1));
        if (object != 0) {
            fn_107_6E5C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
