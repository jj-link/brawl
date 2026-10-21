#pragma force_active on
struct JungleData {
    unsigned char padding[8];
    unsigned int flags : 2;
    unsigned int remaining : 30;
};

extern "C" void fn_51_662C(JungleData* self, unsigned int value) {
    self->flags = value;
}
