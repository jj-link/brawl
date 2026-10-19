#pragma force_active on
extern "C" void* fn_27_1A5FD8(void* member, short deleteFlag);

extern "C" {
void __dl__FPv(void*);

void* fn_104_17954(void* arg1, short arg2) {
    if (arg1 != 0) {
        fn_27_1A5FD8(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}
