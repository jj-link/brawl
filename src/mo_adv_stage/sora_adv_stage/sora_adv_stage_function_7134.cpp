#pragma force_active on
typedef unsigned char u8;

struct CameraController {
    u8 pad[0x40];
    int mode;
};

extern "C" CameraController* getInstance__16CameraControllerFv();

extern "C" int fn_40_7134() {
    if (getInstance__16CameraControllerFv() == 0) {
        return 0;
    }
    if (getInstance__16CameraControllerFv()->mode == 3 ||
        getInstance__16CameraControllerFv()->mode == 4 ||
        getInstance__16CameraControllerFv()->mode == 6) {
        return 0;
    }
    return 1;
}
