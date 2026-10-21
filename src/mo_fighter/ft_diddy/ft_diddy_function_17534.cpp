#pragma force_active on
#pragma always_inline on

namespace {
union DiddyFloatRange {
    struct {
        float minimum;
        float maximum;
    } values;
    struct {
        unsigned long minimum;
        unsigned long maximum;
    } bits;
};

struct DiddyRangeConfiguration {
    const void* vtable;
    unsigned char baseState[4];
    DiddyFloatRange ranges[5];
    bool firstFlag;
    bool secondFlag;
    bool initialized;
};
}

extern "C" {
extern const unsigned char lbl_27_data_13608[];
void* fn_115_175F8(void*, bool);
}

extern "C" DiddyRangeConfiguration* fn_115_17534(
    DiddyRangeConfiguration* configuration, const DiddyFloatRange* first,
    const DiddyFloatRange* second, const DiddyFloatRange* third,
    const DiddyFloatRange* fourth, const DiddyFloatRange* fifth,
    bool firstFlag, bool secondFlag) {
    fn_115_175F8(configuration, false);
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
