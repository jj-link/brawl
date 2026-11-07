#pragma force_active on
#pragma always_inline on

extern "C" {
struct Constants { float a, b, c; };
extern const Constants lbl_27_rodata_1F80;
extern const unsigned char lbl_27_data_13608[];
extern const unsigned char lbl_27_data_2E470[];
}

union Range {
    struct { float minimum, maximum; } values;
    struct { unsigned long minimum, maximum; } bits;
    Range() {}
    Range(float a, float b) { values.minimum = a; values.maximum = b; }
};

struct Configuration {
    const void* vtable;
    unsigned char state0;
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char state2, pad;
    Range ranges[5];
    bool firstFlag, secondFlag, initialized;
    int type;
    float value;
    float field3c;
    float field40;
    float field44;
    float field48;
    unsigned char field4c;

    void init(const Range& a, const Range& b, const Range& c,
              const Range& d, const Range& e, bool f, bool g) {
        vtable = lbl_27_data_13608;
        state0 = 0;
        flag = true;
        state2 = 0;
        ranges[0] = a;
        ranges[1] = b;
        ranges[2] = c;
        ranges[3] = d;
        ranges[4] = e;
        firstFlag = f;
        secondFlag = g;
        initialized = true;
    }
};

extern "C" void fn_27_15D8F8(Configuration* p) {
    const float* base = (const float*)&lbl_27_rodata_1F80;
    p->init(Range(base[1], base[1]), Range(base[1], base[1]),
            Range(base[0], base[0]), Range(base[1], base[1]),
            Range(base[0], base[0]), false, false);
    p->vtable = lbl_27_data_2E470;
    p->type = -1;
    p->value = base[2];
    p->field44 = base[1];
    p->field48 = base[1];
    p->field4c = 0;
}