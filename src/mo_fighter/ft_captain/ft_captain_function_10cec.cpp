#pragma force_active on
class cmPhotoController {
public:
    void setFreezeMode(void* p);
};

class CameraController {
public:
    enum Kind { KIND_0, KIND_1, KIND_2, KIND_3, KIND_4, KIND_5, KIND_6, KIND_7 };
    static CameraController* getInstance();
    cmPhotoController* getCameraController(Kind kind);
};

extern "C" void fn_100_10CEC(void* p) {
    CameraController::getInstance()->getCameraController(CameraController::KIND_7)->setFreezeMode(p);
}
