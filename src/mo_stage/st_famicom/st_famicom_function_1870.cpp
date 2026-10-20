#pragma force_active on
extern "C" const float lbl_68_rodata_0;
extern "C" void* getInstance__16CameraControllerFv();

struct Camera {
    char pad[0x158];
    float left, right, top, bottom;
};

struct Vec {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    char pad[0x1D8];
    Vec a, b;
};

extern "C" void fn_68_1870(Stage* self) {
    Camera* cam = (Camera*)getInstance__16CameraControllerFv();
    self->a.set(cam->left, cam->top, lbl_68_rodata_0);
    self->b.set(cam->right, cam->bottom, lbl_68_rodata_0);
}
