#include <cm/cm_camera_controller.h>
#include <cm/cm_controller_photo.h>
#include <gf/gf_camera_controller.h>
#include <ut/ut_list.h>
#pragma force_active on

extern "C" utListNode lbl_27_bss_6460;

extern "C" void fn_27_29AA20() {
    gfCameraController* cm = !CameraController::getInstance() ? 0 :
        CameraController::getInstance()->getCameraController(CameraController::Photo);
    if (cm) {
        static_cast<cmPhotoController*>(cm)->addCallBack(&lbl_27_bss_6460);
    }
}
