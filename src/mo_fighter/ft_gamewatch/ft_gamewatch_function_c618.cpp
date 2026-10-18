#pragma force_active on
struct FtGamewatchObj {
    unsigned int m_pad[3];
    int *m_counts;
};

extern "C" void fn_107_C618(FtGamewatchObj *self, unsigned int index)
{
    self->m_counts[index] -= 1;
}
