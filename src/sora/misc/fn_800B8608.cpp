#pragma force_active on
// Release a heap allocation when requested, preserving its original pointer.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_800B8608(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
