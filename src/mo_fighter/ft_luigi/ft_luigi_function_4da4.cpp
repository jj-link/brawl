#pragma force_active on
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_99_4E1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_4DA4(void* object, short deleting) {
    if (object) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object) {
            fn_99_4E1C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
