#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
extern const float lbl_63_rodata_0[];
}

struct Camera {
    char pad[0x158];
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
    char pad[0x1EC];
    Vec3 first, second;
};

extern "C" void fn_63_1FA4(Stage* self) {
    Camera* camera = (Camera*)getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->top, lbl_63_rodata_0[0]);
    self->second.set(camera->right, camera->bottom, lbl_63_rodata_0[0]);
}
