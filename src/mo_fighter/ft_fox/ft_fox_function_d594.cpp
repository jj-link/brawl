#pragma force_active on
extern "C" {
void* fn_97_4C84(void* ptr, short count);
void __dl__FPv(void* ptr);

void* fn_97_D594(void* ptr, short flag) {
    if (ptr != 0) {
        fn_97_4C84(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
