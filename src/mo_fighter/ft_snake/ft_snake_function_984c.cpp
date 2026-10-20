#pragma force_active on
extern "C" void* fn_27_D2904(void*, short);
extern "C" void* fn_122_98C4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_984C(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_122_98C4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
