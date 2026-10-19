#pragma force_active on
extern "C" void fn_94_DB58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_DBD0(void* ptr, short flags) {
    if (ptr != 0) {
        fn_94_DB58(ptr, 0);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
