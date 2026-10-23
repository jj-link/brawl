#pragma force_active on
typedef unsigned short u16;

extern "C" const u16 lbl_8040CF10[128][5];

extern "C" void fn_801D3620(int arg0, u16* a1, u16* a2, u16* a3, u16* a4, u16* a5)
{
    int clamped;
    if (arg0 > 0x7F)
        clamped = 0x7F;
    else if (arg0 < 0)
        clamped = 0;
    else
        clamped = arg0;
    *a1 = lbl_8040CF10[clamped][0];
    *a2 = lbl_8040CF10[clamped][1];
    *a3 = lbl_8040CF10[clamped][2];
    *a4 = lbl_8040CF10[clamped][3];
    *a5 = lbl_8040CF10[clamped][4];
}
