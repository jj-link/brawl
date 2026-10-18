#pragma force_active on
extern "C" void fn_104_C88C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C8EC(void* object, short deleting) {
    if (object != 0) {
        fn_104_C88C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
