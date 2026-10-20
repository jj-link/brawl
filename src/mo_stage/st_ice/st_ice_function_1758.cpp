#pragma force_active on
struct CameraController {
    char pad[0x158];
    float left;
    float right;
    float top;
    float bottom;
};

struct Stage {
    char pad[0x420];
    float x1, y1, z1;
    float x2, y2, z2;
};

extern "C" CameraController* getInstance__16CameraControllerFv();
extern const float lbl_62_rodata_0;

extern "C" void fn_62_1758(Stage* self) {
    CameraController* cam = getInstance__16CameraControllerFv();
    float x;
    float y;
    y = cam->top;
    x = cam->left;
    self->x1 = x;
    self->y1 = y;
    self->z1 = lbl_62_rodata_0;

    float x2;
    float y2;
    y2 = cam->bottom;
    x2 = cam->right;
    self->x2 = x2;
    self->y2 = y2;
    self->z2 = lbl_62_rodata_0;
}
