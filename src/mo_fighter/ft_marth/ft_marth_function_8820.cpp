#pragma force_active on
extern "C" {
void fn_106_87C0(void*, short);
void __dl__FPv(void*);

void* fn_106_8820(void* ptr, int flag) {
    if (ptr != 0) {
        fn_106_87C0((char*)ptr + 4, -1);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
