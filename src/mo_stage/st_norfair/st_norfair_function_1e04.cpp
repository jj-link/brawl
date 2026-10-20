#pragma force_active on
extern "C" {
struct CameraController {
    char padding[0x158];
    float left;
    float right;
    float top;
    float bottom;
};

CameraController* getInstance__16CameraControllerFv();
extern const float lbl_54_rodata_0;
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
    char padding[0x774];
    Vec3 first;
    Vec3 second;
};

extern "C" void fn_54_1E04(Stage* self) {
    CameraController* camera = getInstance__16CameraControllerFv();
    self->first.set(camera->left, camera->top, lbl_54_rodata_0);
    self->second.set(camera->right, camera->bottom, lbl_54_rodata_0);
}
