#pragma force_active on

struct Vec3 {
    float x, y, z;
};

extern "C" void fn_800B672C(void* obj, Vec3* out, const char* name);
extern "C" void fn_800B6D10(void* obj, Vec3* out, const char* name);
extern "C" void fn_800B6838(void* obj, const Vec3* pos);

extern "C" char lbl_25_data_A54[];
extern "C" const float lbl_25_rodata_5C;
extern "C" const float lbl_25_rodata_34;

struct Self {
    char pad0[0xf0];
    void* objF0;
    void* objs[0x25];       // 0xf4
    int count;              // 0x188
    char pad18c[0x218 - 0x18c];
    int idx[0x145];         // 0x218
    char names[1][0x20];    // 0x72c
};

extern "C" void fn_25_3470(Self* self) {
    Vec3 pos;
    Vec3 base;
    Vec3 scale;
    float ratio = (float)self->count / lbl_25_rodata_5C;
    fn_800B672C(self->objF0, &base, lbl_25_data_A54);
    fn_800B6D10(self->objF0, &scale, lbl_25_data_A54);
    ratio = lbl_25_rodata_34 / ratio;
    for (int i = 0; i < self->count; i++) {
        int id = self->idx[i];
        fn_800B672C(self->objF0, &pos, self->names[i]);
        pos.x *= scale.x;
        pos.y *= scale.y;
        pos.z *= scale.z;
        pos.z *= ratio;
        pos.x += base.x;
        pos.y += base.y;
        pos.z += base.z;
        fn_800B6838(self->objs[id], &pos);
    }
}
