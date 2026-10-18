#pragma force_active on
extern "C" void fn_106_8880(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_88E0(void* ptr, short flag) {
    if (ptr) {
        fn_106_8880((char*)ptr + 4, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
