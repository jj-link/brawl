#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct SamusWorkHolder {
    u32 m_pad[3];
    s32 *m_values;
};

extern "C" void fn_94_B018(SamusWorkHolder *self, u32 index)
{
    self->m_values[index] -= 1;
}
