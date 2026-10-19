#pragma force_active on
extern "C" void fn_41_57158(void*, short);
extern "C" void fn_41_57058(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_571B8(void* object, short deallocate) {
    if (object != 0) {
        fn_41_57158(static_cast<char*>(object) + 0xF8, -1);
        fn_41_57058(static_cast<char*>(object) + 4, -1);
        if (deallocate > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
