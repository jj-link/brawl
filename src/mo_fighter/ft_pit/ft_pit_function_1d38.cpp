#pragma force_active on
extern "C" {
void fn_112_1B64(void*, short);
void __dl__FPv(void*);

void* fn_112_1D38(void* arg1, short arg2) {
    if (arg1 != 0) {
        fn_112_1B64(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}
