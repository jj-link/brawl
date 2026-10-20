#pragma force_active on
extern "C" const float lbl_51_rodata_0;

struct CameraData {
    char pad[0x158];
    float left;
    float right;
    float top;
    float bottom;
};

extern "C" CameraData* getInstance__16CameraControllerFv();

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Jungle {
    char pad[0x1D8];
    Vec3 first;
    Vec3 second;
};

extern "C" void fn_51_1C60(Jungle* self) {
    CameraData* camera = getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->top, lbl_51_rodata_0);
    self->second.set(camera->right, camera->bottom, lbl_51_rodata_0);
}
