#pragma force_active on
extern "C" void fn_104_4154(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_40F4(void* object, short deleting) {
    if (object != 0) {
        fn_104_4154(static_cast<char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
