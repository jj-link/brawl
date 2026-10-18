#pragma force_active on
extern "C" {
extern const char lbl_117_data_4204[12];

void fn_117_66FC(void* object, char isNull)
{
    *(const char**)object = lbl_117_data_4204;
    *(char*)(4 + (char*)object) = isNull;
}
}
