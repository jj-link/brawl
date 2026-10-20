#pragma force_active on
#pragma always_inline on

extern "C" {
extern const float lbl_27_rodata_E40;
extern const float lbl_27_rodata_E44;
}

union Range {
    struct {
        float minimum, maximum;
    } values;
    struct {
        unsigned long minimum, maximum;
    } bits;

    Range() {}

    void set(float a, float b) {
        values.minimum = a;
        values.maximum = b;
    }

    Range(float a, float b) {
        values.minimum = a;
        values.maximum = b;
    }

    Range& operator=(const Range& other) {
        values.minimum = other.values.minimum;
        values.maximum = other.values.maximum;
        return *this;
    }
};

struct Configuration {
    unsigned char prefix[8];
    Range ranges[5];
    bool firstFlag, secondFlag, initialized;
    Range extra;
    float last;
};

extern "C" void fn_27_B7A98(Configuration* p) {
    Range third;
    Range second;
    Range first(lbl_27_rodata_E44, lbl_27_rodata_E44);
    p->ranges[0] = p->ranges[1] = p->ranges[3] = first;

    second.set(lbl_27_rodata_E40, lbl_27_rodata_E40);
    p->ranges[2] = p->ranges[4] = second;

    p->firstFlag = p->secondFlag = false;
    p->initialized = true;

    third.set(lbl_27_rodata_E44, lbl_27_rodata_E44);
    p->extra = third;
    p->last = lbl_27_rodata_E44;
}
