#pragma force_active on
extern "C" void fn_92_1B7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_1C98(void* object, short shouldDelete) {
    if (object != 0) {
        fn_92_1B7C(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
