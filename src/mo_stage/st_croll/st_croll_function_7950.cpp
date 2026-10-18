#pragma force_active on
extern "C" {
extern unsigned char lbl_90_data_2628[0x50];

unsigned char fn_90_7950(unsigned int idx)
{
    if (idx >= 0x2e)
    {
        return 0;
    }
    return lbl_90_data_2628[idx];
}
}
