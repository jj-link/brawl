#pragma force_active on
extern "C" {
void* getInstance__16CameraControllerFv();
extern const float lbl_49_rodata_10;
}

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Kart {
    char pad[0x1DC];
    Vec3 first;
    Vec3 second;
};

struct Camera {
    char pad[0x158];
    float a, b, c, d;
};

extern "C" void fn_49_B98(Kart* self) {
    Camera* camera = (Camera*)getInstance__16CameraControllerFv();
    self->first.set(camera->a, camera->c, lbl_49_rodata_10);
    self->second.set(camera->b, camera->d, lbl_49_rodata_10);
}
