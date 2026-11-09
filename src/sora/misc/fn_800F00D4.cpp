#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFPCc(void*, const char*);
void* getCameraController__16CameraControllerFQ216CameraController4Kind(void*, int);
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_800A9620(void*, s32);
void fn_800A8DA8(void*, s32);
void fn_800A709C(void*, s32);
void fn_800F1014(void*);
extern char lbl_8059E3A0;
extern char lbl_8059DEC0;
extern char __RTTI__18gfCameraController;

void fn_800F00D4(void* arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char* self = (char*)arg0;
    char* task = (char*)getTask__15gfTaskSchedulerFPCc(getInstance__15gfTaskSchedulerFv(), &lbl_8059E3A0);
    *(s32*)(self + 0x70) = 1;
    *(s32*)(self + 0x50) = *(s32*)(task + 0x40);
    *(s8*)(self + 0x64) = 1;
    char* cam = (char*)__dynamic_cast(getCameraController__16CameraControllerFQ216CameraController4Kind(task, 7), 4, &lbl_8059DEC0, &__RTTI__18gfCameraController, 0);
    if (*(s32*)(cam + 0x60) <= 0) {
        changeInput__16CameraControllerFQ216CameraController4Kind(task, 7);
        fn_800A9620(cam, arg4);
        fn_800A8DA8(cam, 0);
        if (arg3 >= 0) {
            *(s32*)(cam + 0x40) = arg3;
            fn_800A709C(cam, arg3);
        }
    }
    *(s8*)(self + 0x48) = arg1;
    *(s32*)(self + 0x4C) = arg2;
    fn_800F1014(arg0);
    *(s32*)(self + 0x34) = 1;
}
}
