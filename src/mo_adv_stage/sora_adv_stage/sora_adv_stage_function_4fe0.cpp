#pragma force_active on

extern "C" {
extern const float lbl_40_rodata_2C[];
extern const float lbl_40_rodata_7C[];

int stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(
    void*, void*, void*, void*, int, void*, int, unsigned char);

void fn_40_4FE0(void* ths, void* arg1);
}

struct Vec3 {
    float x;
    float y;
    float z;

    void set(float yValue, float xValue, float zValue) {
        x = xValue;
        y = yValue;
        z = zValue;
    }
};

extern "C" void fn_40_4FE0(void* ths, void* arg1) {
    Vec3 v20;
    Vec3 v14;
    Vec3 v8;

    v20.x = lbl_40_rodata_2C[0];
    v20.y = lbl_40_rodata_7C[0];
    v20.z = lbl_40_rodata_2C[0];

    if (stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(
            arg1, &v20, &v14, &v8, 1, 0, 0, 1)) {
        *(float*)((char*)ths + 0x56C) = v14.x;
        *(float*)((char*)ths + 0x570) = v14.y;
        *(float*)((char*)ths + 0x574) = v14.z;
    } else {
        ((Vec3*)((char*)ths + 0x56C))->set(
            ((Vec3*)arg1)->y,
            ((Vec3*)arg1)->x,
            lbl_40_rodata_2C[0]);
    }
}
