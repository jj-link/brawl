#pragma force_active on
extern "C" void fn_41_3AAC4(void*, short);
extern "C" void fn_41_3A9C4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3AB24(void* ptr, short p2) {
    if (ptr != 0) {
        fn_41_3AAC4((char*)ptr + 0xF8, -1);
        fn_41_3A9C4((char*)ptr + 4, -1);
        if (p2 > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
