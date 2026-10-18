#pragma force_active on
extern "C" {
void* fn_115_3D94(void*, short);
void __dl__FPv(void*);

void* fn_115_15440(void* ptr, short flag) {
    if (ptr != 0) {
        fn_115_3D94(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
