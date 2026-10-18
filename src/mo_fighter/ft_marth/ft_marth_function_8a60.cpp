#pragma force_active on
extern "C" {
void fn_106_8A00(void*, short);
void __dl__FPv(void*);

void* fn_106_8A60(void* ptr, int flag) {
    if (ptr != 0) {
        fn_106_8A00((char*)ptr + 8, -1);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
