#include <math.h>
#pragma force_active on

struct ftCommonDataAccesser;

struct PikachuRangeCommonData {
    char pad[0x34];
    const float* horizontalRange;
};

extern ftCommonDataAccesser g_ftCommonDataAccesser;
extern "C" PikachuRangeCommonData* fn_27_148148(ftCommonDataAccesser*);
extern float lbl_98_data_7BE0;

extern "C" int fn_98_14498() {
    const float* range = fn_27_148148(&g_ftCommonDataAccesser)->horizontalRange;
    float value = lbl_98_data_7BE0 / range[1];
    return static_cast<int>(static_cast<float>(fabs(value)));
}
