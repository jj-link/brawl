#pragma force_active on

extern "C" void fn_801EC184(int, void*);

struct Vec3 {
    float x, y, z;
};

struct Obj {
    char pad[0x5020];
    Vec3 pos;
    char pad2[0x30];
    float d, e;
};

extern "C" void fn_80164C0C(Obj* self, const Vec3* src, int arg2, float f1, float f2) {
    self->pos = *src;
    fn_801EC184(arg2, (char*)self + 0x502C);
    self->e = f1;
    self->d = f2;
}
