#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_122_984C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_97D4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_122_984C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
