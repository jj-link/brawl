#pragma force_active on
extern "C" char lbl_100_data_6480[];

extern "C" void fn_100_DC68(void* object)
{
    *static_cast<void**>(object) = lbl_100_data_6480;
}
