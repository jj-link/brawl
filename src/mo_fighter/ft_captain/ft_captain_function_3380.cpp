#pragma force_active on
extern "C" void fn_100_33E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3380(void* object, short shouldDelete) {
    if (object != 0) {
        fn_100_33E0(static_cast<char*>(object) + 8, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
