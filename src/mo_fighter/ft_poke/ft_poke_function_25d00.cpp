#pragma force_active on
extern "C" void* fn_116_3ACC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_25D00(void* object, short deleting) {
    if (object != 0) {
        fn_116_3ACC(static_cast<char*>(object) + 0x38, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
