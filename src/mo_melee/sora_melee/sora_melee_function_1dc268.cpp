#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_458B8[];
extern "C" const char lbl_27_data_CDC0[];

extern "C" void fn_27_1DC268(void* obj, void* value)
{
    void* p = __dynamic_cast(obj, 0, lbl_27_data_458B8, lbl_27_data_CDC0, 0);
    if (p != 0) {
        *(void**)((char*)p + 0x2c) = value;
    }
}
