#pragma force_active on
extern "C" {
extern char lbl_96_data_6994[];

void fn_96_1FD0(void *self, unsigned char v)
{
    *(void **)self = lbl_96_data_6994;
    ((unsigned char *)self)[4] = v;
}
}
