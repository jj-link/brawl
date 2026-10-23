#pragma force_active on
extern int lbl_805A0B60;

void fn_80207CD4(int *arg0, int arg1)
{
    int idx = *(int *)(arg0 + 6);
    char *p = (char *)lbl_805A0B60 + idx * 0x70;
    *(int *)(p + 0x20) = arg1;
    *(int *)(p + 4) |= 0x40000000;
}
