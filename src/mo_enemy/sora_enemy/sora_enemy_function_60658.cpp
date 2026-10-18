#pragma force_active on
extern "C" void fn_41_60968(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_60658(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_60968((char*)ptr + 8, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
