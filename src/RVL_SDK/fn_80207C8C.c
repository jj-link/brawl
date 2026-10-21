#pragma force_active on
extern int lbl_805A0B60;

void fn_80207C8C(void *arg0)
{
    int *p = (int *)(lbl_805A0B60 + ((int *)arg0)[6] * 0x70);
    p[1] = p[1] | 0x10000000 | 8;
}
