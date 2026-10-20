#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_110_553C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_54C4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x470, -1);
        if (object != 0) {
            fn_110_553C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
