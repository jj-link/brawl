#pragma force_active on
struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct CameraController {
    char padding[0x158];
    float left, right, bottom, top;
};

struct Stage {
    char padding[0x400];
    Vec3 minimum;
    Vec3 maximum;
};

extern "C" CameraController* getInstance__16CameraControllerFv();
extern "C" const float lbl_46_rodata_0;

extern "C" void fn_46_1110(Stage* stage) {
    CameraController* camera = getInstance__16CameraControllerFv();
    stage->minimum.set(camera->left, camera->bottom, lbl_46_rodata_0);
    stage->maximum.set(camera->right, camera->top, lbl_46_rodata_0);
}
