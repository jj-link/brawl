#include <stddef.h>
#pragma force_active on

typedef struct {
    unsigned char pad_70[0x70];
    int value;
} PitData;

typedef struct {
    unsigned char pad_d8[0xd8];
    PitData *data;
} Pit;

extern "C" int fn_112_F11C(Pit *self) {
    return self->data->value;
}
