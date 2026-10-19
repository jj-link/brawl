#pragma force_active on
extern "C" void fn_41_60968(void*, short);
extern "C" void fn_41_607FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_60868(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_60968((char*)ptr + 0xF8, -1);
        fn_41_607FC((char*)ptr + 4, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
