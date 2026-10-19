#pragma force_active on
typedef unsigned int u32;

struct fn_77_348C_Owner
{
    unsigned char pad[0x520];
    float* values;
};

extern "C" float fn_77_348C(const fn_77_348C_Owner* self, u32 index)
{
    return self->values[index];
}
