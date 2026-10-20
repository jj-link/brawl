#pragma force_active on
extern "C" unsigned char lbl_95_data_85C0[];

extern "C" void fn_95_144A8(void *object)
{
    *(void **)object = (void *)&lbl_95_data_85C0[0];
}