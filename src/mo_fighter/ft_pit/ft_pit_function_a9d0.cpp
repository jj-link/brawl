#pragma force_active on
typedef unsigned int u32;

struct FtPitWork {
    unsigned char pad[0x1c];
    u32 *m_table;
};

extern "C" void fn_112_A9D0(FtPitWork *self, u32 index)
{
    self->m_table[index] = 0;
}
