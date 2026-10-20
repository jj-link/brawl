#pragma force_active on
extern "C" void* getInstance__16CameraControllerFv();
extern "C" const float lbl_78_rodata_0;

struct Camera {
    char pad[0x148];
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
    char pad[0x238];
    Vec3 first;
    Vec3 second;
};

extern "C" void fn_78_F78(Stage* self) {
    Camera* camera = (Camera*)getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->top, lbl_78_rodata_0);
    self->second.set(camera->right, camera->bottom, lbl_78_rodata_0);
}
