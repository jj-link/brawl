#pragma force_active on
extern "C" void fn_41_69C50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69CBC(void* object, int shouldDelete) {
    if (object != 0) {
        fn_41_69C50(static_cast<char*>(object) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
