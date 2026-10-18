#pragma force_active on
struct FtWorkTable {
    char pad[0xc];
    int *m_values;
};

extern "C" void fn_125_B310(FtWorkTable *self, unsigned int index)
{
    self->m_values[index] = self->m_values[index] - 1;
}
