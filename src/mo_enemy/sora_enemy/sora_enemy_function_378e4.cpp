#pragma force_active on
extern "C" void fn_41_37B18(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_378E4(void* ptr, int flag) {
    if (ptr != 0) {
        fn_41_37B18((char*)ptr + 8, -1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
