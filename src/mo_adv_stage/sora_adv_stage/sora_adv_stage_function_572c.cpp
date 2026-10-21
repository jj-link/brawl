#pragma force_active on

extern "C" {
void* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, unsigned long long, short);

extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];

void fn_40_572C()
{
    char* cam = (char*)getInstance__16CameraControllerFv();
    unsigned long long types =
        ((unsigned long long)(unsigned int)lbl_40_data_1590 << 32) |
        (unsigned int)lbl_40_data_15D8;

    char* p = (char*)__dynamic_cast(
        *(void**)(cam + 0x48), 4, types, 0);

    if (p) {
        *(unsigned int*)(p + 8) &= 0x00FFFFFF;
    }
}
}
