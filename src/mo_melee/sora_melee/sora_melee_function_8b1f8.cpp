#pragma force_active on
#pragma always_inline on

extern "C" {
extern const float lbl_27_rodata_BE0;
extern const float lbl_27_rodata_BE4;
extern const unsigned char lbl_27_data_13608[];
extern const unsigned char lbl_27_data_13848[];
}

union Range {
    struct { float minimum, maximum; } values;
    struct { unsigned long minimum, maximum; } bits;
    Range(float a, float b) {
        values.minimum = a;
        values.maximum = b;
    }
};

struct Configuration {
    const void* vtable;
    unsigned char state0;
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char state2, pad;
    Range ranges[5];
    bool firstFlag, secondFlag, initialized;
    float extra;

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
    void setRange(const Range& r) {
        ranges[2].values.minimum = r.values.minimum;
        ranges[2].values.maximum = r.values.maximum;
    }
};

extern "C" Configuration* fn_27_8B1F8(Configuration* p) {
    p->init(Range(lbl_27_rodata_BE4, lbl_27_rodata_BE4),
            Range(lbl_27_rodata_BE4, lbl_27_rodata_BE4),
            Range(lbl_27_rodata_BE0, lbl_27_rodata_BE0),
            Range(lbl_27_rodata_BE4, lbl_27_rodata_BE4),
            Range(lbl_27_rodata_BE0, lbl_27_rodata_BE0),
            false, false);
    p->vtable = lbl_27_data_13848;
    p->extra = lbl_27_rodata_BE4;
    p->setRange(Range(lbl_27_rodata_BE4, lbl_27_rodata_BE4));
    return p;
}
