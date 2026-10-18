#pragma force_active on
struct FtFloatWork {
    char pad[0x14];
    float* m_floats;
};

extern "C" float fn_108_B250(const FtFloatWork* self, int index) {
    return self->m_floats[index];
}
