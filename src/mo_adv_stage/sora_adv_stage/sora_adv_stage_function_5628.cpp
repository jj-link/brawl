#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];

void fn_40_5628(void*, float* a, float* b)
{
    char* cam = (char*)getInstance__16CameraControllerFv();
    char* p = (char*)__dynamic_cast(
        *(void**)(cam + 0x48), 4,
        lbl_40_data_1590, lbl_40_data_15D8, 0);

    if (p) {
        *(float*)(p + 0x138) = a[0];
        *(float*)(p + 0x13C) = a[1];
        *(float*)(p + 0x140) = a[2];
        *(float*)(p + 0x38) = b[0];
        *(float*)(p + 0x3C) = b[1];
        *(float*)(p + 0x40) = b[2];
    }
}
}
