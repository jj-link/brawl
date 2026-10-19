#pragma force_active on
extern "C" {
void fn_106_815C(void*, short);
void __dl__FPv(void*);

void* fn_106_9320(void* ptr, short flag) {
    if (ptr != 0) {
        fn_106_815C(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
