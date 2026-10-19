#pragma force_active on
extern "C" {
void* fn_56_667C(int* p, int n) {
    int s = p[2] >> 30;
    int t = s + n;
    if (t >= 1) {
        t--;
    }
    return (char*)p + t * 120 + 12;
}
}
