#pragma force_active on
struct FtPitWork {
    char pad[0xc];
    int* m_counts;
};

extern "C" {
void fn_112_AAB4(FtPitWork* self, unsigned int index)
{
    self->m_counts[index]++;
}
}
