#pragma force_active on
struct CrayonData {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int field : 4;
    unsigned int : 24;
};

extern "C" void fn_56_67A8(CrayonData* self, unsigned int value) {
    self->field = value;
}
