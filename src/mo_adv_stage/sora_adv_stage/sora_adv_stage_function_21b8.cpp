#pragma force_active on
class Stage {
public:
    void processFixCamera();
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void* getManager__15gfCameraManagerFv();

extern "C" void fn_40_21B8(Stage* self) {
    char* s = (char*)self;
    if (*(void**)(s + 0x90) != 0 && ((*(unsigned char*)(s + 0x550) >> 7) & 1)) {
        Vec3 pos;
        char* cam = (char*)getManager__15gfCameraManagerFv();
        pos.x = *(float*)(cam + 0x60);
        pos.y = *(float*)(cam + 0x64);
        pos.z = *(float*)(cam + 0x68);
        Vec3* dst = (Vec3*)((char*)*(void**)(s + 0x90) + 0x14);
        dst->x = pos.x;
        dst->y = pos.y;
        dst->z = pos.z;
    }
    self->processFixCamera();
}
