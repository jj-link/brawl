#pragma force_active on
typedef unsigned int u32;

struct PokeWork {
    char pad[0x1c];
    u32 *m_table;
};

extern "C" {
void fn_116_A810(PokeWork *self, u32 index)
{
    self->m_table[index] = 0;
}
}
