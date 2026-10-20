#pragma force_active on
extern const char lbl_27_data_8B410[];
extern const char lbl_27_data_248[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" void* fn_27_33C39C(void* a, void* b)
{
    return __dynamic_cast(*(void**)((char*)b + 8), 0x3c, lbl_27_data_8B410, lbl_27_data_248, 1);
}
