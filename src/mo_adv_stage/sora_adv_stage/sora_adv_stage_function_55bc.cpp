#pragma force_active on
class CameraController;
extern "C" CameraController* getInstance__16CameraControllerFv();
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_40_data_1590[];
extern "C" const char lbl_40_data_15D8[];

extern "C" {
void fn_40_55BC(void* self, float* arg)
{
    CameraController* cam = getInstance__16CameraControllerFv();
    void* p = __dynamic_cast(*(void**)((char*)cam + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
    if (p != 0) {
        *(float*)((char*)p + 0x38) = arg[0];
        *(float*)((char*)p + 0x3C) = arg[1];
        *(float*)((char*)p + 0x40) = arg[2];
    }
}
}
