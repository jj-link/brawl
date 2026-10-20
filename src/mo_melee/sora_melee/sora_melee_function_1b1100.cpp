#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_27_1B1100(u8* self, int idx) {
    int s = *(int*)(self + 8) >> 30;
    if (s + idx >= 1) {
        idx = s + idx - 1;
    } else {
        idx = s + idx;
    }
    return self + idx * 20 + 12;
}
