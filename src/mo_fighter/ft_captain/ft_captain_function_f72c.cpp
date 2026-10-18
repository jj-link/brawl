#pragma force_active on
extern "C" {
extern char lbl_100_data_6608[];

void fn_100_F72C(void *object)
{
    *reinterpret_cast<char **>(object) = lbl_100_data_6608;
}
}
