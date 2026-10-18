#pragma force_active on
struct PitAccesser {
    unsigned char prefix[0x14];
    int firstIndex;
    unsigned char unused[0x28 - 0x18];
    int* rows[1];
};

extern "C" int fn_112_16ADC(PitAccesser* self, void* accesser, int index, int element) {
    return self->rows[index - self->firstIndex][element];
}
