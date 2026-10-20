#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
extern const float lbl_52_rodata_0;
}

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    char pad[0x544];
    Vec3 a;
    Vec3 b;
};

struct Camera {
    char pad[0x158];
    float left, right, top, bottom;
};

extern "C" void fn_52_1DDC(Stage* self) {
    Camera* cam = (Camera*)getInstance__16CameraControllerFv();
    self->a.set(cam->left, cam->top, lbl_52_rodata_0);
    self->b.set(cam->right, cam->bottom, lbl_52_rodata_0);
}
