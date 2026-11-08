#pragma force_active on
#pragma always_inline on
union FloatRange {
    struct { float minimum, maximum; } values;
    struct { unsigned long minimum, maximum; } bits;
};
struct Configuration {
    const void* vtable;
    unsigned char baseState[4];
    FloatRange ranges[5];
    bool firstFlag;
    bool secondFlag;
    bool initialized;
    float value;
};
extern "C" {
extern const unsigned char lbl_27_data_13608[];
extern const unsigned char lbl_27_data_13698[];
void* fn_122_177A8(void*, int);
}
extern "C" Configuration* fn_122_2447C(
    Configuration* self, float value, const FloatRange* first, const FloatRange* second,
    const FloatRange* third, const FloatRange* fourth, const FloatRange* fifth,
    bool flag) {
    fn_122_177A8(self, 0);
    self->vtable = lbl_27_data_13608;
    self->ranges[0] = *first;
    self->ranges[1] = *second;
    self->ranges[2] = *third;
    self->ranges[3] = *fourth;
    self->ranges[4] = *fifth;
    self->firstFlag = flag;
    self->secondFlag = false;
    self->initialized = true;
    self->vtable = lbl_27_data_13698;
    self->value = value;
    return self;
}