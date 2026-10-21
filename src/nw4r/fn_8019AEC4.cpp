#pragma force_active on
struct FloatTableEntry {
    char pad[0x20];
    float* values;
};

extern "C" float fn_8019AEC4(FloatTableEntry* self, int index)
{
    return self->values[index];
}
