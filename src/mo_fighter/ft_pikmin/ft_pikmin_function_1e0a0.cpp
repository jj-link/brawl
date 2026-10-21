#pragma force_active on
namespace {
union PikminFloatRange {
    struct {
        float minimum;
        float maximum;
    } values;
    struct {
        unsigned long minimum;
        unsigned long maximum;
    } bits;
};

struct PikminRangeConfiguration {
    const void* vtable;
    unsigned char baseState[4];
    PikminFloatRange ranges[5];
    bool firstFlag;
    bool secondFlag;
    bool initialized;
};
}

extern "C" {
extern const unsigned char lbl_27_data_13608[];
void* fn_113_1C230(void*, int);
}

extern "C" PikminRangeConfiguration* fn_113_1E0A0(
    PikminRangeConfiguration* configuration, const PikminFloatRange* first,
    const PikminFloatRange* second, const PikminFloatRange* third,
    const PikminFloatRange* fourth, const PikminFloatRange* fifth,
    bool firstFlag, bool secondFlag) {
    fn_113_1C230(configuration, 0);
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
