#pragma force_active on
extern "C" {
extern unsigned char lbl_94_data_50CC[];

void fn_94_6C20(void *obj, unsigned char val)
{
    *(void **)obj = lbl_94_data_50CC;
    ((unsigned char *)obj)[4] = val;
}
}
