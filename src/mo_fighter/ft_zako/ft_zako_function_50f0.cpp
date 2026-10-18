#pragma force_active on
extern "C" {
extern char lbl_126_data_17F4[];

void fn_126_50F0(void *self, unsigned char value)
{
    *(char **)self = lbl_126_data_17F4;
    ((unsigned char *)self)[4] = value;
}
}
