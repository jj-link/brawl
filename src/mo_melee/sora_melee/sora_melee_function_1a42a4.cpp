#include <types.h>
#pragma force_active on

struct Data {
    u8 pad[8];
    s32 bits;
};

extern "C" int fn_27_1A42A4(Data *data) {
    return data->bits >> 22;
}
