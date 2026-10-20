#pragma force_active on
extern "C" void* fn_107_E740(void* object, short deleting);
extern "C" void* fn_107_E608(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_E7A0(void* object, short deleting) {
    if (object != 0) {
        fn_107_E740(static_cast<char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_107_E608(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
