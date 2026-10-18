#pragma force_active on
extern "C" {
extern char lbl_113_data_6C5C[0x40];

void fn_113_6378(void *self, void *arg)
{
    ((void **)self)[0] = lbl_113_data_6C5C;
    ((void **)self)[1] = arg;
}
}
