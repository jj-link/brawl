#pragma force_active on
extern "C" void fn_106_9054(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_90B4(void* ptr, int should_delete) {
    if (ptr != 0) {
        fn_106_9054((char*)ptr + 8, -1);
        if ((short)should_delete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
