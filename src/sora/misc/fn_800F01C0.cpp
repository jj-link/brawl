#pragma force_active on
extern "C" {

void exit__6gfTaskFv(void*);
void* getInstance__15gfTaskSchedulerFv();
void* getTask__15gfTaskSchedulerFPCc(void*, const char*);
void* getCameraController__16CameraControllerFQ216CameraController4Kind(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);

extern char lbl_8059E3A0;
extern char lbl_8059DEC0;
extern char __RTTI__18gfCameraController;

void fn_800F01C0(void* self) {
    void* task = *(void**)((char*)self + 0x5C);
    if (task) {
        exit__6gfTaskFv(task);
        *(void**)((char*)self + 0x5C) = 0;
    }
    void* cameraTask = getTask__15gfTaskSchedulerFPCc(
        getInstance__15gfTaskSchedulerFv(), &lbl_8059E3A0);
    void* camera = getCameraController__16CameraControllerFQ216CameraController4Kind(cameraTask, 7);
    void* casted = __dynamic_cast(camera, 4, &lbl_8059DEC0, &__RTTI__18gfCameraController, 0);
    if (*(int*)((char*)casted + 0x60) <= 0) {
        changeInput__16CameraControllerFQ216CameraController4Kind(cameraTask, *(int*)((char*)self + 0x50));
    }
}

}
