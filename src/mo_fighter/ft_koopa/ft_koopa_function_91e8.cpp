#pragma force_active on
typedef unsigned int u32;

struct FloatArrayOwner {
    char pad[0x14];
    float *m_floats;
};

extern "C" void fn_102_91E8(FloatArrayOwner *self, u32 index, float value)
{
    self->m_floats[index] *= value;
}
