#pragma force_active on

struct Camera {
    char pad0[0x100];
    int projection;
    char pad104[0x10];
    float x, y, width, height, nearZ, farZ;
    unsigned short left, top, right, bottom;
};

struct Context {
    void* message;
    int count;
    float x, y, width, height;
};

extern "C" void clearMsgBuf__7MessageFv(void*);
extern "C" void fn_80018610(void*);
extern "C" void setGX__8gfCameraFv(void*);
extern "C" void drawBoxLine__7MessageFlllfffff(
    int, int, int, float, float, float, float, float);

extern "C" const float lbl_90_rodata_0;
extern "C" const float lbl_90_rodata_128;
extern "C" const float lbl_90_rodata_12C;
extern "C" const float lbl_90_rodata_130;

extern "C" void fn_90_8230(Context* self) {
    Camera camera;

    clearMsgBuf__7MessageFv(self->message);
    if (self->count > 0) {
        fn_80018610(&camera);
        camera.projection = 0;
        camera.x = lbl_90_rodata_0;
        camera.y = lbl_90_rodata_0;
        camera.width = lbl_90_rodata_128;
        camera.height = lbl_90_rodata_12C;
        camera.nearZ = lbl_90_rodata_0;
        camera.farZ = lbl_90_rodata_130;
        camera.left = 0;
        camera.top = 0;
        camera.right = 640;
        camera.bottom = 480;
        setGX__8gfCameraFv(&camera);
        drawBoxLine__7MessageFlllfffff(
            255, 0, 0,
            self->x, self->y, self->width, self->height,
            lbl_90_rodata_0);
    }
}
