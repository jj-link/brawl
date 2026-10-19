#pragma force_active on
typedef struct {
    char pad[0x14];
    const float* floats;
} FloatTable;

extern "C" float fn_110_9930(const FloatTable* self, unsigned int index) {
    return self->floats[index];
}
