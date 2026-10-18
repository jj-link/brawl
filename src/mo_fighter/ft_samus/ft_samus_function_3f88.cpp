#pragma force_active on
extern "C" void fn_27_2EFC10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_3F88(void* object, short deleting) {
    if (object != 0) {
        fn_27_2EFC10(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
