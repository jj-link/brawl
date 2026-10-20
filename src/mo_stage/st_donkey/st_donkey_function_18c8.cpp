#pragma force_active on
struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Camera {
    unsigned char pad[0x158];
    float left, right, bottom, top;
};

struct Stage {
    unsigned char pad[0x3DC];
    Vec3 first, second;
};

extern "C" Camera* getInstance__16CameraControllerFv();
extern "C" const float lbl_50_rodata_0;

extern "C" void fn_50_18C8(Stage* self) {
    Camera* camera = getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->bottom, lbl_50_rodata_0);
    self->second.set(camera->right, camera->top, lbl_50_rodata_0);
}
