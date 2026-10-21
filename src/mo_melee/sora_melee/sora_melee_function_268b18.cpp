#pragma force_active on

extern "C" void __ct__10grYakumonoFPCc(void* self, const char* name);
extern "C" char lbl_27_data_562C8[];
extern "C" const float lbl_27_rodata_42E8;
extern "C" const float lbl_27_rodata_42EC;

struct Vec3f {
    float x, y, z;

    Vec3f(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct grYakumonoPunchSlider {
    grYakumonoPunchSlider(const char* name);
};

grYakumonoPunchSlider::grYakumonoPunchSlider(const char* name) {
    __ct__10grYakumonoFPCc(this, name);
    *(char**)((char*)this + 0x3c) = lbl_27_data_562C8;
    *(int*)((char*)this + 0x1b0) = 0;
    *(int*)((char*)this + 0x1b4) = 0;
    *(int*)((char*)this + 0x1b8) = 0;
    *(int*)((char*)this + 0x1bc) = 0;
    *(int*)((char*)this + 0x1c0) = 0;
    *(int*)((char*)this + 0x150) = 0;
    *(unsigned char*)((char*)this + 0x158) = 0;
    *(int*)((char*)this + 0x154) = 0;
    *(int*)((char*)this + 0x180) = -1;
    *(int*)((char*)this + 0x184) = -1;
    *(Vec3f*)((char*)this + 0x168) =
        Vec3f(lbl_27_rodata_42E8, lbl_27_rodata_42E8, lbl_27_rodata_42E8);
    *(Vec3f*)((char*)this + 0x174) =
        Vec3f(lbl_27_rodata_42EC, lbl_27_rodata_42EC, lbl_27_rodata_42EC);
    *(int*)((char*)this + 0xe4) = 20;
}
