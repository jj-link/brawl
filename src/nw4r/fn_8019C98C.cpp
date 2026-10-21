#pragma force_active on
extern "C" {
extern void fn_8019D88C(void* ptr, int flag);

void* fn_8019C98C(void* arg0) {
    if (arg0 != 0) {
        fn_8019D88C(arg0, 0);
    }
    return arg0;
}
}
