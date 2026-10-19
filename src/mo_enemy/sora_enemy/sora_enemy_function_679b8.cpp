#pragma force_active on
extern "C" void* fn_41_67958(void*, short);
extern "C" void* fn_41_67858(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_679B8(void* ptr, int flag) {
    if (ptr) {
        fn_41_67958((char*)ptr + 0xF8, -1);
        fn_41_67858((char*)ptr + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
