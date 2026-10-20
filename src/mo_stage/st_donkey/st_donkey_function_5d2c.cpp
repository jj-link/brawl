#pragma force_active on
struct DonkeyData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_50_5D2C(const DonkeyData* self) {
    return (self->flags >> 25) & 1u;
}
