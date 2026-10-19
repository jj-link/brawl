#pragma force_active on
extern "C" {
void fn_121_1BB4(void* arg1, short arg2);
void __dl__FPv(void* arg);

void* fn_121_1C18(void* arg1, short arg2) {
    if (arg1 != 0) {
        fn_121_1BB4(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}
