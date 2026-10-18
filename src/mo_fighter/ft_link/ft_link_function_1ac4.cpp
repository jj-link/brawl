#pragma force_active on
extern "C" extern int lbl_93_data_3CB4[3];

extern "C" void fn_93_1AC4(void *self, int type)
{
    ((void **)self)[0] = (void *)lbl_93_data_3CB4;
    ((unsigned char *)self)[4] = (unsigned char)type;
}
