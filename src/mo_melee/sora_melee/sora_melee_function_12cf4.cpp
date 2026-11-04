#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Target {
    int unk0;
    float unk4;
    float unk8;
    float unkC;
    char pad10[0x0c];
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
};

class Module {
public:
    virtual void v0();
    virtual Target* v1(int);
};

struct Self {
    char pad[0x30];
    int unk30;
    Module* unk34;
};

extern "C" void fn_27_12CF4(Self* self, int arg1, Vec3* a, Vec3* b, Vec3* c) {
    if (self->unk30 != 0) {
        Target* t = self->unk34->v1(arg1);
        float ax = a->x;
        float ay = a->y;
        t->unk4 = ax;
        float az = a->z;
        t->unk8 = ay;
        t->unkC = az;
        t = self->unk34->v1(arg1);
        float bx = b->x;
        float by = b->y;
        t->unk1C = bx;
        float bz = b->z;
        t->unk20 = by;
        t->unk24 = bz;
        t = self->unk34->v1(arg1);
        float cx = c->x;
        float cy = c->y;
        t->unk28 = cx;
        float cz = c->z;
        t->unk2C = cy;
        t->unk30 = cz;
    }
}
