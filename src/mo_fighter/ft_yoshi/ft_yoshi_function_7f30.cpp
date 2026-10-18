#pragma force_active on
extern "C" {
extern char lbl_95_data_3794[];

void fn_95_7F30(void *self, unsigned char v)
{
    *(char **)self = lbl_95_data_3794;
    ((unsigned char *)self)[4] = v;
}
}
