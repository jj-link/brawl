#pragma force_active on
extern "C" {
void fn_97_1B88(void*, short);
void __dl__FPv(void*);

void* fn_97_1D5C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_97_1B88(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
