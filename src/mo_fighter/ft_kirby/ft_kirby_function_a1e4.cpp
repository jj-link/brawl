#pragma force_active on
extern "C" {
extern int lbl_96_data_6290[];

void fn_96_A1E4(int *r3, int r4, int r5, int r6)
{
    *(int *)r3 = (int)lbl_96_data_6290;
    *(int *)(r3 + 4) = r4;
    *(int *)(r3 + 5) = r5;
    *(int *)(r3 + 6) = r6;
}
}
