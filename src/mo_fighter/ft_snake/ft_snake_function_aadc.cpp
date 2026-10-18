#pragma force_active on
extern char lbl_122_data_8D54[];

extern "C" void fn_122_AADC(void *self, unsigned char val)
{
    *(void **)self = lbl_122_data_8D54;
    *((unsigned char *)self + 4) = val;
}
