#pragma force_active on
struct JungleData {
    unsigned int padding[2];
    unsigned int flags : 3;
    unsigned int reserved : 29;
};

extern "C" void fn_51_D890(JungleData* self, unsigned int value) {
    self->flags = value;
}
