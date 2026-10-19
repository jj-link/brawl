#pragma force_active on
struct St_B844 {
    int f0;
    int f4;
    int f8;
};

extern "C" {
char* fn_48_B844(St_B844* self, int index) {
    int t = (self->f8 >> 25) + index;
    if (t >= 0x3a) {
        t -= 0x3a;
    }
    return (char*)self + t * 0x38 + 0xc;
}
}
