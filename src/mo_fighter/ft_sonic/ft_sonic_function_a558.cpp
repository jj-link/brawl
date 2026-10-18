#pragma force_active on
typedef unsigned int u32;

struct FtSonicWork {
    char pad[0xc];
    u32* m_values;
};

extern "C" {
void fn_123_A558(FtSonicWork* self, u32 value, u32 index)
{
    self->m_values[index] += value;
}
}
