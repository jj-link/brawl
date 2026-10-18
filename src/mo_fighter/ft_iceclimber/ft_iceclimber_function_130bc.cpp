#pragma force_active on
extern "C" unsigned char lbl_105_data_7F10[];

extern "C" void fn_105_130BC(void *object)
{
    *(void **)object = (void *)lbl_105_data_7F10;
}