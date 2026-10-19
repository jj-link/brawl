#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_100_3F74(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5B74(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(ptr) + 0x10, -1);
        fn_100_3F74(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
