#pragma force_active on
struct PeachData {
    unsigned int padding[2];
    unsigned int value : 6;
    unsigned int remaining : 26;
};

extern "C" void fn_103_F6F0(PeachData* self, unsigned int value) {
    self->value = value;
}
