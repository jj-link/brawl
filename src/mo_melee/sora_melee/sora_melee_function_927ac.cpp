#pragma force_active on
extern "C" {
void* fn_27_927AC(int* p, int n) {
    int i = (p[2] >> 22) + n;
    if (i >= 500) {
        i -= 500;
    }
    return (char*)p + i * 8 + 12;
}
}
