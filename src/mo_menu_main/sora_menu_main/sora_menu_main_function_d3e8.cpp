#include <cm/cm_camera_controller.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_2_98B4(void*, int, int);
extern char lbl_2_data_1360[];
extern char lbl_2_data_718[];
extern float lbl_2_rodata_360;
}
extern "C" void fn_2_D3E8(char* self) {
    char* cam = (char*)CameraController::getInstance();
    char* p = (char*)__dynamic_cast(*(void**)(cam + 0x48), 4, lbl_2_data_1360, lbl_2_data_718, 0);
    int index = -1;
loop:
    index++;
    if (index >= 4) index = 0;
    if (index == -1) {
        index = -1;
    } else if (!(((unsigned char)self[index * 0x14 + 0x4c] >> 7) & 1)) {
        goto loop;
    }
    *(int*)(self + 0x244) = index;
    for (int i = 0; i < 4; i++) {
        fn_2_98B4(self, i, 0);
    }
    fn_2_98B4(self, index, 1);
    MuObject* obj = *(MuObject**)(self + 0x118);
    float frame = lbl_2_rodata_360;
    obj->setFrameVisible(frame);
    obj->setFrameNode(frame);
    *(char*)(self + 0x230) = 1;
    *(int*)(self + 0x2fc) = *(int*)(p + 0x40);
}