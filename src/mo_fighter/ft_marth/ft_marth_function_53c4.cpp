#pragma force_active on
extern "C" {
extern char lbl_106_data_18AC[12];

void fn_106_53C4(void* object, char isNull)
{
    *(char**)object = lbl_106_data_18AC;
    *(char*)(4 + (char*)object) = isNull;
}
}
