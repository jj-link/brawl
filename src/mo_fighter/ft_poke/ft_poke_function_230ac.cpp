#pragma force_active on
extern "C" void fn_116_3ACC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_230AC(void* object, short deleting) {
    if (object != 0) {
        fn_116_3ACC(static_cast<char*>(object) + 0x54, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
