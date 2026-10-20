#pragma force_active on
struct PictoChatData
{
    char pad[0x5b0];
    float *m_data;
};

extern "C" float fn_73_9B4C(const PictoChatData *self, unsigned index)
{
    return self->m_data[index];
}
