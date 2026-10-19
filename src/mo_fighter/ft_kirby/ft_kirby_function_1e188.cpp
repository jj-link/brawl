#pragma force_active on
struct KirbyData {
    unsigned char padding[8];
    unsigned int value : 6;
    unsigned int remaining : 26;
};

extern "C" void fn_96_1E188(KirbyData* self, unsigned int value) {
    self->value = value;
}
