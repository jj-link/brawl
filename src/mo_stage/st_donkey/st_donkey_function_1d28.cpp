#include <types.h>
#pragma force_active on

// st_donkey.rel: one of the stage object's small init routines - the two
// byte-sized members at object offsets 0x3fc and 0x3fd are both set to 3.
// (r3 = pointer to the object being initialised.)
struct StDonkeyStageData {
    u8 _pad[0x3fc];
    u8 byte_3fc;
    u8 byte_3fd;
    u8 tail[0x2];
};

extern "C" {
void fn_50_1D28(StDonkeyStageData *data)
{
    data->byte_3fc = 3;
    data->byte_3fd = 3;
}
}
