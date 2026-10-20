#pragma force_active on
extern "C" void* fn_27_AAAAC(void* self, int idx) {
    idx = ((int*)self)[2] >> 27 ? idx : idx;
    int t = (((int*)self)[2] >> 27) + idx;
    if (t >= 12) {
        t -= 12;
    }
    return (char*)self + 12 + t * 4;
}
