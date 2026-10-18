#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_115_3D94(void* ptr, short flag) {
    if (ptr != 0 && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
