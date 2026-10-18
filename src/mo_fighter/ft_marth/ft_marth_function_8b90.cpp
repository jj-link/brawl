#pragma force_active on
extern "C" void fn_106_8B30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8B90(void* ptr, int flag) {
    if (ptr) {
        fn_106_8B30((char*)ptr + 4, -1);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
