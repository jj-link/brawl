#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_801D3AD4(void* arg, int flag) {
    if (arg != 0 && flag > 0) {
        __dl__FPv(arg);
    }
    return arg;
}
}
