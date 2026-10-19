#pragma force_active on
struct FloatArrayOwner
{
    char padding[0x1570];
    const float *values;
};

extern "C" float fn_79_40A4(const FloatArrayOwner *self, unsigned int index)
{
    return self->values[index];
}
