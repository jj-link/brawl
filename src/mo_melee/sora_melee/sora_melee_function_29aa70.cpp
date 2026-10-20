#pragma force_active on
class utListNode;

class gfCameraController {
public:
    virtual ~gfCameraController() {}
};

class CameraController {
public:
    enum Kind { Photo = 7 };
    static CameraController* getInstance();
    gfCameraController* getCameraController(Kind kind);
};

class cmPhotoController : public gfCameraController {
public:
    void removeCallBack(utListNode* node);
};

extern utListNode lbl_27_bss_6460;

extern "C" void fn_27_29AA70() {
    gfCameraController* cm = !CameraController::getInstance() ? 0 :
        CameraController::getInstance()->getCameraController(CameraController::Photo);
    if (cm) {
        static_cast<cmPhotoController*>(cm)->removeCallBack(&lbl_27_bss_6460);
    }
}
