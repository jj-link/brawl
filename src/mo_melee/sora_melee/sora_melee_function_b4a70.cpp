#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

union FloatBits {
    float f;
    unsigned int i;
};

extern "C" char* getManager__15gfCameraManagerFv();
extern const float lbl_27_rodata_DFC;

extern "C" void fn_27_B4A70(Vec3* v) {
    char* cam = getManager__15gfCameraManagerFv();
    if (cam == 0) {
        v->x = lbl_27_rodata_DFC;
        v->y = lbl_27_rodata_DFC;
        v->z = lbl_27_rodata_DFC;
    } else {
        Vec3 tmp;
        tmp.x = *(float*)(cam + 0x60);
        tmp.y = *(float*)(cam + 0x64);
        tmp.z = *(float*)(cam + 0x68);
        FloatBits* src = (FloatBits*)&tmp.x;
        FloatBits* dst = (FloatBits*)&v->x;
        dst[0].i = src[0].i;
        dst[1].i = src[1].i;
        dst[2].i = src[2].i;
    }
}
