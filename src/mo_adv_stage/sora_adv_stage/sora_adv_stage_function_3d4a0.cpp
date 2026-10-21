#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Object {
    char pad0[0x150];
    int state;
    char pad154[0x5c];
    float timer;
};

extern "C" {
extern const float lbl_40_rodata_848[];

void getPos__9grGimmickFv(Vec3*, void*);
void setPos__9grGimmickFP5Vec3f(void*, Vec3*);

void fn_40_3D4A0(Object* self) {
    const float* data = lbl_40_rodata_848;
    Vec3 pos;

    getPos__9grGimmickFv(&pos, self);
    self->timer += data[0x94 / 4];
    if (self->timer >= data[0x98 / 4]) {
        self->state = 2;
        self->timer = data[0];
    }
    pos.y += data[0x94 / 4];
    setPos__9grGimmickFP5Vec3f(self, &pos);
}
}
