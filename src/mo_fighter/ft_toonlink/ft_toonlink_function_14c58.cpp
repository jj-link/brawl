#pragma force_active on
extern "C" unsigned char lbl_121_data_9008[0x40];

extern "C" void fn_121_14C58(void *object)
{
    *(void **)object = (void *)&lbl_121_data_9008[0];
}
