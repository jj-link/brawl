#pragma force_active on
extern "C" const float lbl_61_rodata_0;

struct CameraData {
    char pad[0x158];
    float left;
    float right;
    float top;
    float bottom;
};

extern "C" CameraData* getInstance__16CameraControllerFv();

struct StageData {
    char pad[0x964];
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
};

extern "C" void fn_61_17B4(StageData* self) {
    CameraData* camera = getInstance__16CameraControllerFv();

    float x;
    float y = camera->top;
    x = camera->left;
    self->minX = x;
    self->minY = y;
    self->minZ = lbl_61_rodata_0;

    float x2;
    float y2 = camera->bottom;
    x2 = camera->right;
    self->maxX = x2;
    self->maxY = y2;
    self->maxZ = lbl_61_rodata_0;
}
