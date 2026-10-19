#pragma force_active on
extern "C" void* fn_92_3364(void*, short);
extern "C" void* fn_92_4F04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_32F4(void* object, short deleting) {
    if (object != 0) {
        fn_92_3364(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        fn_92_4F04(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
