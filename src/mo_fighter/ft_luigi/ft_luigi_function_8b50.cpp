#pragma force_active on
struct LuigiFloatTable {
    unsigned char padding[0x14];
    float* values;
};

extern "C" float fn_99_8B50(const LuigiFloatTable* self, unsigned int index) {
    return self->values[index];
}
