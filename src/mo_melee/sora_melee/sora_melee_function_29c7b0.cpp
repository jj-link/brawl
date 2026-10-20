#include <cm/cm_camera_controller.h>
#include <cm/cm_controller_photo.h>
#include <gf/gf_camera_controller.h>
#include <ut/ut_list.h>
#include <types.h>
#pragma force_active on

extern "C" u8 lbl_27_bss_6480[];

struct fn_27_VObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f26(int, int, int);
};

extern "C" void fn_27_29C7B0(void* unused, u8* p) {
    u8* a = *(u8**)(p + 0x60);
    a = *(u8**)(a + 0xd8);
    a = *(u8**)(a + 0x88);
    ((fn_27_VObj*)a)->f26(4, 0, 0);

    gfCameraController* cm = !CameraController::getInstance() ? 0 :
        CameraController::getInstance()->getCameraController(CameraController::Photo);
    if (cm) {
        static_cast<cmPhotoController*>(cm)->removeCallBack(reinterpret_cast<utListNode*>(lbl_27_bss_6480));
    }
}
