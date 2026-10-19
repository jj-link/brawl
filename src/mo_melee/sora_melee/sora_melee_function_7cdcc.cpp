#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_27_7CDCC(void* arg, int count);
}

extern "C" void* fn_27_7CDCC(void* arg, int count) {
    if (arg != 0 && count > 0) {
        __dl__FPv(arg);
    }
    return arg;
}
