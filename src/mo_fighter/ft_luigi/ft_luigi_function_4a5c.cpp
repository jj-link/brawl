#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_99_4AD4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_4A5C(void* object, short deleting) {
    if (object) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, -1);
        if (object) {
            fn_99_4AD4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
