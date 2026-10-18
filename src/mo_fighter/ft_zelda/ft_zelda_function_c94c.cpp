#pragma force_active on
extern "C" void fn_104_C8EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C94C(void* object, short deleting) {
    if (object != 0) {
        fn_104_C8EC(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
