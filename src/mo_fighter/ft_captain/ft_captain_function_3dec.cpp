#pragma force_active on
extern "C" void* fn_100_3E4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3DEC(void* ptr, short size) {
    if (ptr != 0) {
        fn_100_3E4C(static_cast<char*>(ptr) + 0xC, -1);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
