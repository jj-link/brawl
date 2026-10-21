#pragma force_active on
extern void __dl__FPv(void*);

void* fn_80278B0C(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
