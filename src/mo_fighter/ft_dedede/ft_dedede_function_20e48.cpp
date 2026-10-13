#pragma always_inline on
namespace {
union DededeFloatRange {
    struct {
        float minimum;
        float maximum;
    } values;
    struct {
        unsigned long minimum;
        unsigned long maximum;
    } bits;
};

struct DededeRangeConfiguration {
    const void* vtable;
    unsigned char baseState[4];
    DededeFloatRange ranges[5];
    bool firstFlag;
    bool secondFlag;
    bool initialized;
};
}

extern "C" {
extern const unsigned char lbl_27_data_13608[];
void* fn_117_20F0C(void*, bool);
}

extern "C" DededeRangeConfiguration* fn_117_20E48(
    DededeRangeConfiguration* configuration, const DededeFloatRange* first,
    const DededeFloatRange* second, const DededeFloatRange* third,
    const DededeFloatRange* fourth, const DededeFloatRange* fifth,
    bool firstFlag, bool secondFlag) {
    fn_117_20F0C(configuration, false);
    configuration->vtable = lbl_27_data_13608;
    configuration->ranges[0] = *first;
    configuration->ranges[1] = *second;
    configuration->ranges[2] = *third;
    configuration->ranges[3] = *fourth;
    configuration->ranges[4] = *fifth;
    configuration->firstFlag = firstFlag;
    configuration->secondFlag = secondFlag;
    configuration->initialized = true;
    return configuration;
}
