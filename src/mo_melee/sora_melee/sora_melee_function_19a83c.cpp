#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_19A83C(void* arg1, int arg2) {
    if (arg1 != 0 && arg2 > 0) {
        __dl__FPv(arg1);
    }
    return arg1;
}
}
