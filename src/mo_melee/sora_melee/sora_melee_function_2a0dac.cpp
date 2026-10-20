#pragma force_active on
extern "C" void* fn_27_2A0DAC(void* p1, int p2)
{
    extern void* lbl_27_data_73488;
    extern void* lbl_27_data_731C0[];

    if (p2 < 0 || p2 >= 0xB2)
        return &lbl_27_data_73488;
    return lbl_27_data_731C0[p2];
}
