#pragma force_active on
extern "C" {
void fn_27_7700(void*, short);
void __dl__FPv(void*);

void* fn_108_1F14(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_7700(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
