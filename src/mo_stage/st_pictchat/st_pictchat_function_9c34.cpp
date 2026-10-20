#pragma force_active on
struct StWork {
    char pad[0x7f0];
    float* floatWorks;
};

extern "C" float fn_73_9C34(const StWork* self, unsigned int index) {
    return self->floatWorks[index];
}
