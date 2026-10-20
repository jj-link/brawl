#pragma force_active on
struct CameraController {
    char padding[0x158];
    float left, right, top, bottom;
};

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    char padding[0x1E0];
    Vec3 min, max;
};

extern "C" CameraController* getInstance__16CameraControllerFv();
extern "C" const float lbl_81_rodata_0;

extern "C" void fn_81_153C(Stage* self) {
    CameraController* camera = getInstance__16CameraControllerFv();
    self->min.set(camera->left, camera->top, lbl_81_rodata_0);
    self->max.set(camera->right, camera->bottom, lbl_81_rodata_0);
}
