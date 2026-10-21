#pragma force_active on
struct FamicomData {
    unsigned int padding[2];
    unsigned int flags : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_68_6540(FamicomData* self, unsigned int value) {
    self->flags = value;
}
