#pragma force_active on
typedef unsigned char u8;

struct GanonAccesser {
    u8 prefix[0x14];
    int firstIndex;
    u8 unused[0x10];
    int *rows[33];
};

extern "C" int fn_109_11A94(GanonAccesser *self, void *accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
