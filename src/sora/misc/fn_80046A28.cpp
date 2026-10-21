#pragma force_active on
extern "C" {
extern void fn_801B33D8(void* p, int flag);

void* fn_80046A28(void* arg0) {
    if (arg0 != 0) {
        fn_801B33D8(arg0, 0);
    }
    return arg0;
}
}
