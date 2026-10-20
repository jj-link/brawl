#pragma force_active on
struct IceFloatWork {
    unsigned char pad[0x5b0];
    float* m_floatWorks;
};

extern "C" float fn_62_5538(const IceFloatWork* self, unsigned int index) {
    return self->m_floatWorks[index];
}
