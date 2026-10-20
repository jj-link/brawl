#pragma force_active on
extern "C" {
extern const unsigned char lbl_27_rodata_2A60[];

int fn_27_1DCBE8(int idx)
{
    return (lbl_27_rodata_2A60[idx] >> 3) & 1;
}
}
