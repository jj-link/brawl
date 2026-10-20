#pragma force_active on
extern "C" const float lbl_71_rodata_0;

struct CameraController {
    char pad[0x158];
    float left;
    float right;
    float top;
    float bottom;
};

extern "C" CameraController* getInstance__16CameraControllerFv();

struct Stage {
    char pad[0x27C];
    float ax, ay, az;
    float bx, by, bz;
};

extern "C" void fn_71_14CC(Stage* self) {
    CameraController* camera = getInstance__16CameraControllerFv();

    float x;
    float y = camera->top;
    x = camera->left;
    self->ax = x;
    self->ay = y;
    self->az = lbl_71_rodata_0;

    float x2;
    float y2 = camera->bottom;
    x2 = camera->right;
    self->bx = x2;
    self->by = y2;
    self->bz = lbl_71_rodata_0;
}
