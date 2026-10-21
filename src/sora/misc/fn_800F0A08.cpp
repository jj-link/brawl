#pragma force_active on
extern "C" {
int fn_800F0A08(int a0, void* p, unsigned long arg2) {
    unsigned long* q = (unsigned long*)p;
    int r = 0;
    if (q[0] != 0)
        goto end;
    if (q[1] < arg2)
        goto end;
    r = 1;
end:
    return r;
}
}
