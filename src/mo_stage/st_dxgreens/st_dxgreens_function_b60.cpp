#pragma force_active on
extern "C" const float lbl_79_rodata_0;

struct CameraController {
    char pad[0x158];
    float left, right, top, bottom;
};

extern "C" CameraController* getInstance__16CameraControllerFv();

struct Vec {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    char pad[0x1d8];
    Vec a, b;
};

extern "C" void fn_79_B60(Stage* self) {
    CameraController* camera = getInstance__16CameraControllerFv();
    self->a.set(camera->left, camera->top, lbl_79_rodata_0);
    self->b.set(camera->right, camera->bottom, lbl_79_rodata_0);
}
