#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" void fn_8009D2B0(void* p);

extern "C" void fn_27_29BFF4() {
    if (CameraController::getInstance()) {
        fn_8009D2B0(CameraController::getInstance());
    }
}
