#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_36C8(void* arg, short flag) {
    if (arg != 0 && flag > 0) {
        __dl__FPv(arg);
    }
    return arg;
}
