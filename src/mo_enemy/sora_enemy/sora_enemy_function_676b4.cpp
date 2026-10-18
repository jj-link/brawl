#pragma force_active on
extern "C" void* fn_41_676B4(void* ptr, int flag);
extern "C" void fn_41_67958(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_676B4(void* ptr, int flag) {
    if (ptr) {
        fn_41_67958((char*)ptr + 8, -1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
