#pragma force_active on
extern "C" unsigned char lbl_100_data_62A0[];

extern "C" void fn_100_D478(void* output)
{
    *static_cast<void**>(output) = lbl_100_data_62A0;
}
