#pragma force_active on
extern "C" void* fn_27_296124(int* base, int idx) {
    int s = base[2] >> 26;
    int t = s + idx;
    if (t >= 30) {
        t -= 30;
    }
    return (char*)base + t * 12 + 12;
}
