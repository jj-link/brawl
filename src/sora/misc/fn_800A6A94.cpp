#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_800A6A94(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
}
