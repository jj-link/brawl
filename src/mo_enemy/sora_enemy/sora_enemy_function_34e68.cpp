#pragma force_active on
extern "C" void fn_41_FB10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_34E68(void* ptr, int flag) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_41_FB10(ptr, 0);
        }
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
