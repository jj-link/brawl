#pragma force_active on
#pragma always_inline on

extern "C" {
extern const float lbl_27_rodata_27A0;
extern const float lbl_27_rodata_27A4;
extern const unsigned char lbl_27_data_13608[];
extern const unsigned char lbl_27_data_45730[];
}

union Range {
    struct {
        float minimum, maximum;
    } values;
    struct {
        unsigned long minimum, maximum;
    } bits;

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
    int type;

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

extern "C" void fn_27_1DBA64(Configuration* p) {
    p->init(Range(lbl_27_rodata_27A4, lbl_27_rodata_27A4),
            Range(lbl_27_rodata_27A4, lbl_27_rodata_27A4),
            Range(lbl_27_rodata_27A0, lbl_27_rodata_27A0),
            Range(lbl_27_rodata_27A4, lbl_27_rodata_27A4),
            Range(lbl_27_rodata_27A0, lbl_27_rodata_27A0),
            false, false);
    p->vtable = lbl_27_data_45730;
    p->type = -1;
}
