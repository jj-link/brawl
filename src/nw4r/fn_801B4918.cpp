#pragma force_active on
extern "C" {
void fn_801AC1AC(void* a, int b);

void* fn_801B4918(void* arg0) {
    if (arg0 != 0) {
        fn_801AC1AC(arg0, 0);
    }
    return arg0;
}
}
