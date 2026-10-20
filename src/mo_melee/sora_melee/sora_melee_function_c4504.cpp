#pragma force_active on
extern "C" {
void* fn_27_C4504(void* self, int idx) {
    int* ip = (int*)self;
    int v = ip[2] >> 26;
    int t = v + idx;
    idx = (t >= 20) ? t - 20 : t;
    return (char*)self + 12 + idx * 4;
}
}
