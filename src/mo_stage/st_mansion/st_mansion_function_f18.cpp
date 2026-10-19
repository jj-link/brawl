#pragma force_active on
extern "C" const float lbl_47_rodata_0;
class CameraController;
extern "C" CameraController* getInstance__16CameraControllerFv();

extern "C" void fn_47_F18(void* self) {
    char* cam = (char*)getInstance__16CameraControllerFv();
    char* s = (char*)self;
    float z;
    float b;
    float a;
    float d;
    float c;
    a = *(float*)(cam + 0x160);
    b = *(float*)(cam + 0x158);
    z = lbl_47_rodata_0;
    *(float*)(s + 0x1d8) = b;
    *(float*)(s + 0x1dc) = a;
    *(float*)(s + 0x1e0) = z;
    c = *(float*)(cam + 0x164);
    d = *(float*)(cam + 0x15c);
    *(float*)(s + 0x1e4) = d;
    *(float*)(s + 0x1e8) = c;
    *(float*)(s + 0x1ec) = z;
}
