#pragma force_active on
// Release a runtime allocation when requested, preserving its pointer.
extern "C" {
void __dl__FPv(void*);
void* fn_801B885C(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
}
