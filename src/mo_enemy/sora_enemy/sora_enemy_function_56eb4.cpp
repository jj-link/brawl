#pragma force_active on
extern "C" void fn_41_57158(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_56EB4(void* object, int shouldDelete) {
    if (object != 0) {
        fn_41_57158(static_cast<char*>(object) + 8, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
