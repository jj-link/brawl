#pragma force_active on
// Release a heap block when requested, preserving its pointer.
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_8000CEE8(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
}
