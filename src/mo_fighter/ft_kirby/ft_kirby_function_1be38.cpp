#pragma force_active on
extern "C" void fn_96_1BDB4(void*, void*, void*, float, int);

extern "C" void fn_96_1BE38(float* out, float* a, float* b, float delta, int enabled) {
    fn_96_1BDB4(out, a, b, delta, enabled);
    if (enabled) {
        if (a[1] > b[1])
            out[1] = a[1] + delta;
        else
            out[1] = b[1] + delta;
    } else {
        out[1] = out[1] + delta;
    }
}
