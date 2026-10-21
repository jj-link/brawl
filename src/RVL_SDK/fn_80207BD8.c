#pragma force_active on
extern int lbl_805A0B60;

void fn_80207BD8(char *arg0, int arg1)
{
    int *p;
    p = (int *)(lbl_805A0B60 + *(int *)(arg0 + 0x18) * 0x70);
    p[2] = arg1;
    p[1] |= 0x10000000;
}
