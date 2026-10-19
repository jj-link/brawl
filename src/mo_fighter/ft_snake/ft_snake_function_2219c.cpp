#pragma force_active on
extern "C" void* fn_122_738C(void*, short);
extern "C" void* fn_122_22738(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2219C(void* object, short deleting) {
    if (object != 0) {
        fn_122_738C(static_cast<char*>(object) + 0x2570, -1);
        fn_122_22738(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
