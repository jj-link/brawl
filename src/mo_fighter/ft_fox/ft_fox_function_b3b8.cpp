#pragma force_active on
struct FloatArrayOwner {
    char pad[0x14];
    float *m_floats;
};

extern "C" void fn_97_B3B8(FloatArrayOwner *self, unsigned int index, float value)
{
    self->m_floats[index] += value;
}
