#pragma force_active on
extern "C" {
void fn_27_1540CC(void*, short);
void __dl__FPv(void*);

void* fn_27_37B220(void* ptr, int flag) {
    if (ptr) {
        fn_27_1540CC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
