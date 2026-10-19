#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void* ctrl, int kind);
extern float lbl_37_rodata_0;
}

extern "C" void fn_37_1424(u8* self) {
    changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
    u8* p = *(u8**)(self + 0x88);
    float f = lbl_37_rodata_0;
    float a = *(float*)(p + 0x4);
    *(float*)(self + 0xB4) = a;
    *(u32*)(self + 0xBC) = *(u16*)(p + 0x8);
    *(float*)(self + 0xB8) = f;
    *(u8*)(self + 0x7D) = 0;
    *(u8*)(self + 0xC8) = 1;
}
