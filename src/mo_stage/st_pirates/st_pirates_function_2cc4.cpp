#pragma force_active on
extern "C" const float lbl_52_rodata_0[];

extern "C" {
void fn_27_233C70(void*, void*);
unsigned char* getInstance__16CameraControllerFv();
float fn_8016232C(float);
float fn_801622C4(float);
void fn_8009CEA8(void*, void*);
}

struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};

struct Rect {
    float a, b, c, d;
};

extern "C" void fn_52_2CC4(unsigned char* self) {
    const float* rodata = lbl_52_rodata_0;
    float* params;
    if (*(void**)(self + 0x5FC) && *(void**)(self + 0x600) &&
        (params = *(float**)(self + 0x9C))) {
        float z = *(float*)(self + 0x330);
        float y = *(float*)(self + 0x320);
        float x = *(float*)(self + 0x310);
        Vec pos(x, y, z);
        *(float*)(*(unsigned char**)(self + 0x600) + 0x28) = pos.y;
        *(float*)(*(unsigned char**)(self + 0x600) + 0x30) =
            *params * *(float*)(self + 0x604);
        unsigned char* data = *(unsigned char**)(self + 0x600);
        *(float*)(data + 0x20) =
            rodata[5] + (*(float*)(self + 0x550) - *(float*)(self + 0x544));
        *(float*)(data + 0x24) =
            rodata[39] + (pos.y - *(float*)(self + 0x554));
        *(float*)(data + 0x18) = pos.x;
        *(float*)(data + 0x1C) =
            pos.y - rodata[40] * *(float*)(data + 0x24);
        fn_27_233C70(*(void**)(self + 0x5FC), *(void**)(self + 0x600));
        float offset = rodata[0];
        Rect rect = *(Rect*)(getInstance__16CameraControllerFv() + 0x148);
        if (rect.d < pos.y) {
            rect.d = pos.y;
            unsigned char* camera = getInstance__16CameraControllerFv() + 0x84;
            if (camera) {
                float s = fn_8016232C(rodata[41]);
                float c = fn_801622C4(rodata[41]);
                rect.d -= rodata[40] * (*(float*)(camera + 0x10) * (c / s));
            }
            offset = pos.y - rect.d;
        }
        fn_8009CEA8(getInstance__16CameraControllerFv(), &rect);
        *(float*)(getInstance__16CameraControllerFv() + 0x18C) = offset;
    }
}
