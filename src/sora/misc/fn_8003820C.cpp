#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern int* lbl_805A0098;

void* fn_8003820C(void* arg0, int arg1) {
    if (arg0) {
        lbl_805A0098 = 0;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
