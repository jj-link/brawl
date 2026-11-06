#pragma force_active on

struct S {
    unsigned char pad[0x30];
    signed char axis[4];
};

static inline int clamp(int value, int low, int high) {
    int lower = value > low ? value : low;
    return lower < high ? lower : high;
}

static inline void decay(signed char& value) {
    if (value >= 0) {
        value = clamp(value - 15, 0, 127);
    } else {
        value = clamp(value + 15, -128, 0);
    }
}

extern "C" void fn_800288A4(S* s) {
    decay(s->axis[0]);
    decay(s->axis[1]);
    decay(s->axis[2]);
    decay(s->axis[3]);
}
