#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_99_4B4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_4AD4(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x1FC, -1);
        if (object) {
            fn_99_4B4C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
