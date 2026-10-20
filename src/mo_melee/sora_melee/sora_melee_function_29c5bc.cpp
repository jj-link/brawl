#include <cm/cm_camera_controller.h>
#include <cm/cm_controller_photo.h>
#include <gf/gf_camera_controller.h>
#include <ut/ut_list.h>
#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_bss_6480[];

extern "C" void fn_27_29C5BC() {
    gfCameraController* cm = !CameraController::getInstance() ? 0 :
        CameraController::getInstance()->getCameraController(CameraController::Photo);
    if (cm) {
        static_cast<cmPhotoController*>(cm)->addCallBack(reinterpret_cast<utListNode*>(lbl_27_bss_6480));
    }
}
