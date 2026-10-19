#pragma force_active on
extern "C" char* fn_51_6488(char* self, int n) {
    int t = *(int*)(self + 8);
    int s = (t >> 30) + n;
    if (s < 1) {
        s = s;
    } else {
        s = s - 1;
    }
    return self + s * 0xa0 + 0xc;
}
