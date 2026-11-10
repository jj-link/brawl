#pragma force_active on

extern "C" {
void* fn_106_36E8(void*, short);
void __dl__FPv(void*);

void* fn_106_3688(void* ptr, short flag) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_106_36E8(ptr, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
