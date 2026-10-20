#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_96_5608(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_5680(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_96_5608(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
