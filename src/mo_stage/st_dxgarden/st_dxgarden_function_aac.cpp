#pragma force_active on
extern "C" void* getInstance__16CameraControllerFv();
extern "C" const float lbl_77_rodata_0;

struct Stage {
    char pad[0x1dc];
    float x1, y1, z1, x2, y2, z2;
};

extern "C" void fn_77_AAC(Stage* self) {
    float* camera = (float*)getInstance__16CameraControllerFv();

    float x;
    float y;
    y = camera[0x160 / 4];
    x = camera[0x158 / 4];
    self->x1 = x;
    self->y1 = y;
    self->z1 = lbl_77_rodata_0;

    float x2;
    float y2;
    y2 = camera[0x164 / 4];
    x2 = camera[0x15c / 4];
    self->x2 = x2;
    self->y2 = y2;
    self->z2 = lbl_77_rodata_0;
}
