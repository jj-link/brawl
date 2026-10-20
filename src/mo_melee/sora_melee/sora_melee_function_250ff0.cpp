#pragma force_active on
extern "C" {
void fn_27_247E58(void*, int);
void __dl__FPv(void*);

void* fn_27_250FF0(void* arg1, int arg2) {
    if (arg1) {
        fn_27_247E58(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}
