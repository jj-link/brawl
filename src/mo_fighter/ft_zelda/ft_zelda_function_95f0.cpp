#pragma force_active on
extern "C" {
extern char lbl_104_data_2894[];

void fn_104_95F0(char *self, void *a, void *b, void *c)
{
    *(void **)(self + 0x0) = lbl_104_data_2894;
    *(void **)(self + 0x10) = a;
    *(void **)(self + 0x14) = b;
    *(void **)(self + 0x18) = c;
}
}
