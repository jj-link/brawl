#pragma force_active on
extern "C" {
extern const float lbl_74_rodata_0;
void* getInstance__16CameraControllerFv();

void fn_74_170C(char* self) {
    char* cam = (char*)getInstance__16CameraControllerFv();
    float a;
    float b;
    b = *(float*)(cam + 0x164);
    a = *(float*)(cam + 0x15c);
    *(float*)(self + 0x3ac) = a;
    *(float*)(self + 0x3b0) = b;
    *(float*)(self + 0x3b4) = lbl_74_rodata_0;
}
}
