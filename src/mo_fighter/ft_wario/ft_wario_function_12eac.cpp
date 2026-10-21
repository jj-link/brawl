#pragma force_active on
namespace {
union WarioFloatRange {
    struct {
        float minimum;
        float maximum;
    } values;
    struct {
        unsigned long minimum;
        unsigned long maximum;
    } bits;
};

struct WarioRangeConfiguration {
    const void* vtable;
    unsigned char baseState[4];
    WarioFloatRange ranges[5];
    unsigned char firstFlag;
    unsigned char secondFlag;
    unsigned char initialized;
};
}

extern "C" {
extern const unsigned char lbl_27_data_13608[];
WarioRangeConfiguration* fn_110_12F70(WarioRangeConfiguration* object, int nullable);
}

extern "C" WarioRangeConfiguration* fn_110_12EAC(
    WarioRangeConfiguration* object, const WarioFloatRange* first,
    const WarioFloatRange* second, const WarioFloatRange* third,
    const WarioFloatRange* fourth, const WarioFloatRange* fifth,
    unsigned char firstFlag, unsigned char secondFlag) {
    fn_110_12F70(object, 0);
    object->vtable = lbl_27_data_13608;
    object->ranges[0] = *first;
    object->ranges[1] = *second;
    object->ranges[2] = *third;
    object->ranges[3] = *fourth;
    object->ranges[4] = *fifth;
    object->firstFlag = firstFlag;
    object->secondFlag = secondFlag;
    object->initialized = 1;
    return object;
}
