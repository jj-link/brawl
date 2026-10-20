#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
extern const float lbl_48_rodata_0;
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
    char pad[0x1ec];
    Vec3 first;
    Vec3 second;
};

struct Camera {
    char pad[0x158];
    float left, right, top, bottom;
};

extern "C" void fn_48_C68(Stage* self) {
    Camera* camera = (Camera*)getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->top, lbl_48_rodata_0);
    self->second.set(camera->right, camera->bottom, lbl_48_rodata_0);
}
