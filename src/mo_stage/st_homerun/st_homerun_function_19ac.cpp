#pragma force_active on
extern "C" const float lbl_88_rodata_0[];

struct Camera {
    char pad[0x148];
    float x1, x2, y1, y2;
};

extern "C" Camera* getInstance__16CameraControllerFv();

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    char pad[0x560];
    Vec3 first, second;
};

extern "C" void fn_88_19AC(Stage* self) {
    Camera* camera = getInstance__16CameraControllerFv();
    self->first.set(camera->x1, camera->y1, lbl_88_rodata_0[0]);
    self->second.set(camera->x2, camera->y2, lbl_88_rodata_0[0]);
}
