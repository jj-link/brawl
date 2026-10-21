#pragma force_active on
struct KartData {
    unsigned char padding[8];
    unsigned int field : 4;
    unsigned int unused : 28;
};

extern "C" void fn_49_6FA4(KartData* self, unsigned int value) {
    self->field = value;
}
