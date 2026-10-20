#pragma force_active on
extern "C" void* fn_41_42A80(void* ptr, short flag);
extern "C" void* fn_41_429B0(char* self, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_42AE0(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_42A80((char*)ptr + 0xcc, -1);
        if (ptr != 0)
            fn_41_429B0((char*)ptr, 0);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
