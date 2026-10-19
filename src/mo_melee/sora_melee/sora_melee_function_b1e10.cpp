#pragma force_active on
extern "C" {
struct CameraController;
CameraController* getInstance__16CameraControllerFv();
void fn_8009CE3C(CameraController*, int);

void fn_27_B1E10() {
    CameraController* camera = getInstance__16CameraControllerFv();
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(camera) + 0x40) == 11) {
        camera = getInstance__16CameraControllerFv();
        fn_8009CE3C(camera, 0);
    }
}
}
