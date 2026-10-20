#pragma force_active on
extern "C" void fn_113_4730(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_EE84(void* ptr, short count) {
    if (ptr) {
        if (ptr && (char*)ptr + 4 && (char*)ptr + 0xc && (char*)ptr + 0x10) {
            fn_113_4730((char*)ptr + 0x10, 0);
        }
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
