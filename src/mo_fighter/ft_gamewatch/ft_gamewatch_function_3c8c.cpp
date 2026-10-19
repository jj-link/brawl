#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_107_3CE8(void* ptr, short count);

extern "C" void* fn_107_3C8C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_107_3CE8(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
