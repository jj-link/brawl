#pragma force_active on
struct MarioData {
    unsigned char pad[12];
    int *values;
};

extern "C" void fn_91_A898(MarioData *self, int divisor, int index) {
    if (divisor != 0) {
        self->values[index] = self->values[index] / divisor;
    }
}
