#pragma force_active on
class CameraController;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_800A58C0(void*, void*, float, int);
extern "C" const float lbl_40_rodata_2C[];
extern "C" const char lbl_40_data_1590[];
extern "C" const char lbl_40_data_15D8[];
extern "C" CameraController* getInstance__16CameraControllerFv();

extern "C" {
void fn_40_5E74(void* self, void* obj)
{
    CameraController* cam = getInstance__16CameraControllerFv();
    void* p = __dynamic_cast(*(void**)((char*)cam + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
    if (p != 0) {
        fn_800A58C0(p, obj, lbl_40_rodata_2C[0], 0);
    }
}
}
