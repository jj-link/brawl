#pragma force_active on
extern "C" void fn_100_AB4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_ABAC(void* object, int shouldDelete) {
    if (object != 0) {
        fn_100_AB4C(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
