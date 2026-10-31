#pragma force_active on
extern "C" void *fn_102_7DE0(void *a, int b);

extern "C" void *fn_102_12C50(void *r3, int r4)
{
    switch (r4) {
    case 0:
        return r3;
    case 1:
        return (char *)r3 + 0x49c;
    case 2:
        return fn_102_7DE0(r3, r4);
    default:
        if (r4 >= 3) {
            return fn_102_7DE0(r3, r4);
        }
        return fn_102_7DE0(r3, r4);
    }
}
