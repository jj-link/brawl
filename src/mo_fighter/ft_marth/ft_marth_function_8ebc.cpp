#pragma force_active on
extern "C" {
extern void fn_106_8E60(void*, short);
extern void __dl__FPv(void*);

void* fn_106_8EBC(void* ptr, short flag) {
    if (ptr != 0) {
        fn_106_8E60((char*)ptr + 4, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
